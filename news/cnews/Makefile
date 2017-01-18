# Created by: adam
# $FreeBSD$

PORTNAME=	cnews
PORTVERSION=	cr.g
PORTREVISION=	17
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/c-news/ \
		ftp://ftp.funet.fi/pub/unix/news/cnews/ \
		ftp://ftp.redcom.ru/pub/unix/usenet/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/ \
		ftp://ftp.dinoex.org/pub/c-news/:pgp
DISTNAME=	c-news
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pgpverify-1.12:pgp
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.dinoex.org/pub/c-news/
PATCHFILES=	c-news-patch-fileart.c c-news-patch-namelen \
		c-news-patch-newsrun c-news-patch-sendbatches2 \
		c-news-patch-ctl-pgp3 c-news-patch-ctl-more \
		c-news-patch-ctl-regexp \
		c-news-patch-doexpire c-news-patch-queuelen.tay \
		c-news-patch-bunzip2 \
		c-news-patch-ctl-underscore \
		c-news-patch-y2k-2 \
		c-news-patch-inews-path \
		c-news-patch-gawk3 \
		c-news-patch-ansi \
		c-news-patch-pgpverify-1.12-perl4

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	News server

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

MAKE_JOBS_UNSAFE=	yes

USES=		tar:Z
USE_CSTD=	gnu89
CFLAGS+=	-Wno-return-type

DIST_SUBDIR=	${DISTNAME}
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
SUB_FILES=	pkg-message
LMAN1=		checknews.1cn inews.1cn postnews.1cn readnews.1cn
LMAN5=		controlperm.5 news.5 newsctl.5 newsdb.5 newsoverview.5 \
		newssys.5
LMAN8=		cnewsdo.8cn expire.8cn explode.8cn mergeactive.8 \
		mkhistory.8cn newsaux.8cn newsbatch.8cn newsmail.8cn \
		newsmaint.8cn newsoverview.8 relaynews.8cn report.8cn \
		rnews.8cn
NO_EG_FILES=	active.times inews organization postdefltgroup readnews.ctl \
		readnews.help report.ctl versionname
NEWSCTL_FILES=	active active.times batchparms controlperm explist \
		history history.dir history.pag inews mailname mailpaths \
		organization postdefltgroup readnews.ctl readnews.help \
		report.ctl sys versionname whoami

SUB_LIST+=	NEWSCTL=${NEWSCTL}
PLIST_SUB+=	VARBASE=${VARBASE}
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=^${PREFIX}/==}
PLIST_SUB+=	NEWSCTL=${NEWSCTL:S=^${VARBASE}/==}
PLIST_SUB+=	NEWSCTLBASE=${NEWSCTL:S=/news==:S=^${VARBASE}/==}
PLIST_SUB+=	NEWSARTS=${NEWSARTS:S=^${VARBASE}/==}
PLIST_SUB+=	NEWSOV=${NEWSOV:S=^${VARBASE}/==}
PLIST_SUB+=	NEWSCTL_FILES="${NEWSCTL_FILES}"

OPTIONS_DEFINE=	SENDMAIL EXAMPLES
OPTIONS_DEFAULT=PGPGPG
OPTIONS_SINGLE=	VERIFY
OPTIONS_SINGLE_VERIFY=	PGP2 PGPIN PGPGPG
SENDMAIL_DESC=	use sendmail instead of /bin/mail
PGP2_DESC=	use pgp-2.6.3ia for control messages
PGPIN_DESC=	use pgp-2.6.3in for control messages
PGPGPG_DESC=	use pgpgpg for control messages

VARBASE?=	/var
NEWSBIN?=	${PREFIX}/libexec/cnews
NEWSCTL?=	${VARBASE}/lib/news
NEWSARTS?=	${VARBASE}/news
NEWSOV?=	${VARBASE}/news/over.view
PGPVERIFY?=	pgpverify-1.12

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSENDMAIL}
EXTRA_PATCHES+=	${FILESDIR}/sendmail.patch
.endif

pre-patch:
	${SED} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|' \
		${DISTDIR}/${DIST_SUBDIR}/${PGPVERIFY} \
		> ${WRKSRC}/${PGPVERIFY}

post-patch:
	@${REINPLACE_CMD} -e 's/getline/get_line/g' ${WRKSRC}/readnews/active.c \
		${WRKSRC}/readnews/newsrc.c

pre-configure:
.for i in conf/quiz.def conf/substitutions include/config.make
	${REINPLACE_CMD} \
		-e "s=/usr/local/news/lib/bin/config=${NEWSBIN}/config=" \
		-e "s=/usr/local/news/cnewsbin=${NEWSBIN}=" \
		-e "s=/usr/local/news/lib=${NEWSCTL}=" \
		-e "s=/var/news/over.view=${NEWSOV}=" \
		-e "s=/var/news=${NEWSARTS}=" \
		-e "s=/usr/local/bin=${PREFIX}/bin=" \
		${WRKSRC}/${i}
.endfor
.if ${PORT_OPTIONS:MPGPIN}
	${REINPLACE_CMD} -e "s|'/usr/local/bin/pgp'|'/usr/local/bin/pgpin'|" \
		${WRKSRC}/${PGPVERIFY}
.endif
.if ${PORT_OPTIONS:MPGPGPG}
	${REINPLACE_CMD} -e "s|'/usr/local/bin/pgp'|'/usr/local/bin/pgpgpg'|" \
		${WRKSRC}/${PGPVERIFY}
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libdbz/dbz.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libcnews.a ${STAGEDIR}${PREFIX}/lib/
	${MKDIR} ${STAGEDIR}${NEWSARTS} ${STAGEDIR}${NEWSOV} \
		${STAGEDIR}${NEWSCTL} ${STAGEDIR}${NEWSBIN}
	${INSTALL_SCRIPT} ${WRKSRC}/${PGPVERIFY} ${STAGEDIR}${NEWSBIN}/pgpverify
	${INSTALL_SCRIPT} ${WRKSRC}/conf/config ${STAGEDIR}${NEWSBIN}/
	cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE} install
	cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} ${MAKE_FLAGS} ${MAKEFILE} ui readpostcheck
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${LMAN1} ${STAGEDIR}${PREFIX}/man/man1/
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${LMAN5} ${STAGEDIR}${PREFIX}/man/man5/
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${LMAN8} ${STAGEDIR}${PREFIX}/man/man8/
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsctl
	cd ${WRKSRC} && ${INSTALL_DATA} ${NO_EG_FILES:S,^,*/,} \
		${STAGEDIR}${EXAMPLESDIR}/newsctl/
.for f in active batchparms controlperm explist mailname mailpaths sys whoami
	cd ${WRKSRC} && ${CP} -p */${f}.eg ${STAGEDIR}${EXAMPLESDIR}/newsctl/${f}
.endfor
	${TOUCH} ${STAGEDIR}${EXAMPLESDIR}/newsctl/history
	cd ${STAGEDIR}${EXAMPLESDIR}/newsctl && \
		${STAGEDIR}${NEWSBIN}/dbz history
.endif
.for d in control junk news/announce/newusers news/announce news \
	in.coming/bad in.coming out.going out.master out.nntp
	${MKDIR} ${STAGEDIR}${NEWSARTS}/${d}
.endfor

test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} r)

.include <bsd.port.mk>
