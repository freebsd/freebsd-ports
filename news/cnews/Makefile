# New ports collection makefile for:	cnews
# Date created:		28 September 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	cnews
PORTVERSION=	cr.g
PORTREVISION=	3
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/c-news/ \
		ftp://ftp.funet.fi/pub/unix/news/cnews/ \
		ftp://ftp.redcom.ru/pub/unix/usenet/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/
DISTNAME=	c-news
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pgpverify-1.12
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.lan-ks.de/pub/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/
PATCHFILES=	c-news-patch-fileart.c c-news-patch-namelen \
		c-news-patch-newsrun c-news-patch-sendbatches \
		c-news-patch-ctl-pgp3 c-news-patch-ctl-more \
		c-news-patch-ctl-regexp \
		c-news-patch-doexpire c-news-patch-queuelen.tay \
		c-news-patch-bunzip2 \
		c-news-patch-ctl-underscore \
		c-news-patch-y2k-2 \
		c-news-patch-inews-path \
		c-news-patch-pgpverify-1.12-perl4

MAINTAINER=	dinoex@FreeBSD.org

DIST_SUBDIR=	${DISTNAME}
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		checknews.1cn inews.1cn postnews.1cn readnews.1cn
MAN5=		controlperm.5 news.5 newsctl.5 newsdb.5 newsoverview.5 \
		newssys.5
MAN8=		cnewsdo.8cn expire.8cn explode.8cn mergeactive.8 \
		mkhistory.8cn newsaux.8cn newsbatch.8cn newsmail.8cn \
		newsmaint.8cn newsoverview.8 relaynews.8cn report.8cn \
		rnews.8cn
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=${PREFIX}/==}
PLIST_SUB+=	NEWSCTL=${NEWSCTL:S=${PREFIX}/==}
PLIST_SUB+=	NEWSARTS=${NEWSARTS:S=${PREFIX}/==}
PLIST_SUB+=	NEWSOV=${NEWSOV:S=${PREFIX}/==}

MODIFY=		conf/quiz.def \
		conf/substitutions \
		include/config.make

NEWSBIN?=	${PREFIX}/news/cnewsbin
NEWSCTL?=	${PREFIX}/news/lib
NEWSARTS?=	/var/news
NEWSOV?=	/var/news/over.view
PGPVERIFY?=	pgpverify-1.12

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
.if make(makesum) || defined(FETCH_ALL)
PATCHFILES+=	c-news-patch-gawk3
.endif
.else
PATCHFILES+=	c-news-patch-gawk3
.endif

check:
	cd ${WRKSRC} && ${MAKE} -${MAKEFLAGS} r

pre-patch:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${PGPVERIFY} ${WRKSRC}/${PGPVERIFY}

pre-configure:
.for i in ${MODIFY}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} \
		-e "s=/usr/local/news/lib/bin/config=${NEWSBIN}/config=" \
		-e "s=/usr/local/news/cnewsbin=${NEWSBIN}=" \
		-e "s=/usr/local/news/lib=${NEWSCTL}=" \
		-e "s=/var/news/over.view=${NEWSOV}=" \
		-e "s=/var/news=${NEWSARTS}=" \
		-e "s=/usr/local/bin=${PREFIX}/bin=" \
		${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor

do-install:
	${RM} -f ${PREFIX}/bin/inews
	${INSTALL_DATA} ${WRKSRC}/libdbz/dbz.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libcnews.a ${PREFIX}/lib
	${MKDIR} ${NEWSARTS} ${NEWSOV} ${NEWSBIN} ${NEWSCTL}
	${CHOWN} ${BINOWN}:${BINGRP} ${NEWSBIN}
	${INSTALL_SCRIPT} ${WRKSRC}/${PGPVERIFY} ${NEWSBIN}/pgpverify
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} setup
	cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ui readpostcheck
.for f in checknews cnewsdo inews injnews postnews readnews
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/bin/$f
.endfor
	${CHOWN} -R news:news ${NEWSARTS} ${NEWSOV} ${NEWSCTL}
	${CHOWN} news:news ${NEWSBIN}/input/newsspool
	${CHMOD} 6555 ${NEWSBIN}/input/newsspool
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man1
.endfor
.for i in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man5
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${PREFIX}/man/man8
.endfor
	@${ECHO} ""
	@${ECHO} "!!!!!!!!"
	@${ECHO} "you MUST change the configuration of this news setup:"
	@${ECHO} "	cd to ${NEWSCTL} and change the following files..."
	@${ECHO} "mailname, whoami, organization, mailpaths, sys, readnews.ctl, postdefltgroup"
	@${ECHO} "	to suit your local system and news topology."
	@${ECHO} "check that you have vaild aliases in report.ctl,"
	@${ECHO} "	so any problem can be reported."
	@${ECHO} "!!!!!!!!"
	@${ECHO} ""

test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} r)

.include <bsd.port.post.mk>
