# New ports collection makefile for:	nntp
# Date created:		29 September 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	nntp
PORTVERSION=	1.5.12.2
PORTREVISION=	4
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.dinoex.org/pub/c-news/
DISTNAME=	${PORTNAME}.${PORTVERSION}

PATCH_SITES=	ftp://ftp.dinoex.org/pub/c-news/
PATCHFILES=	nntp-patch-y2k

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	NNTP with NOV support

BUILD_DEPENDS=	${LOCALBASE}/lib/libcnews.a:${PORTSDIR}/news/cnews

NO_WRKSUBDIR=	yes
MAN1=		nntpxmit.1
MAN8=		nntpd.8c acttimes.8c
PLIST_SUB+=	VARBASE=${VARBASE}
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=^${PREFIX}/==}
PLIST_SUB+=	NEWSCTL=${NEWSCTL:S=^${VARBASE}/==}

MODIFY=		conf.h Makefile
DOCSFILES1=	AUTHORIZE CHANGES README README-conf.h SYSLOG doc/rfc977
DOCSFILES2=	server support xfer xmit

VARBASE?=	/var
NEWSBIN?=	${PREFIX}/libexec/cnews
NEWSCTL?=	${VARBASE}/lib/news
NEWSARTS?=	${VARBASE}/news
NEWSOV?=	${VARBASE}/news

MAKE_ENV+=	DBLIBS="${LOCALBASE}/lib/libcnews.a -lcrypt -lutil"
MAKE_ENV+=	ETCDIR="${LOCALBASE}/sbin" BINDIR="${NEWSBIN}"
MAKE_ENV+=	MANDIR="${LOCALBASE}/man"

post-extract:
	@${CP} ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

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
		-e "s=/usr/local/sbin=${PREFIX}/sbin=" \
		-e "s=/usr/local/man=${PREFIX}/man=" \
		${WRKSRC}/${i}.sed >${WRKSRC}/${i}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/overview.fmt ${NEWSCTL}/overview.fmt
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCSFILES1}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.for i in ${DOCSFILES2}
	${INSTALL_DATA} ${WRKSRC}/${i}/README ${DOCSDIR}/${i}-README
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
