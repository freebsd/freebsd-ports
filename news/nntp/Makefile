# Created by: Adam David <adam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nntp
PORTVERSION=	1.5.12.2
PORTREVISION=	7
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.dinoex.org/pub/c-news/
DISTNAME=	${PORTNAME}.${PORTVERSION}

PATCH_SITES=	ftp://ftp.dinoex.org/pub/c-news/
PATCHFILES=	nntp-patch-y2k

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	NNTP with NOV support

BUILD_DEPENDS=	${LOCALBASE}/lib/libcnews.a:news/cnews

NO_WRKSUBDIR=	yes
PLIST_SUB+=	VARBASE=${VARBASE}
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=^${PREFIX}/==}
PLIST_SUB+=	NEWSCTL=${NEWSCTL:S=^${VARBASE}/==}

DOCSFILES1=	AUTHORIZE CHANGES README README-conf.h SYSLOG doc/rfc977
DOCSFILES2=	server support xfer xmit

VARBASE?=	/var
NEWSBIN?=	${PREFIX}/libexec/cnews
NEWSCTL?=	${VARBASE}/lib/news
NEWSARTS?=	${VARBASE}/news
NEWSOV?=	${VARBASE}/news/over.view

MAKE_ENV+=	DBLIBS="${LOCALBASE}/lib/libcnews.a -lcrypt -lutil"
MAKE_ENV+=	ETCDIR="${STAGEDIR}${PREFIX}/sbin"
MAKE_ENV+=	BINDIR="${STAGEDIR}${NEWSBIN}"
MAKE_ENV+=	MANDIR="${STAGEDIR}${PREFIX}/man"

OPTIONS_DEFINE=	INETD DOCS
NO_OPTIONS_SORT=yes
INETD_DESC=	build to run from inetd only

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINETD}
ALONE=	-e 's|\#define.ALONE|\#undef	ALONE|'
.endif

post-extract:
	${CP} ${WRKSRC}/conf.h.dist ${WRKSRC}/conf.h

pre-configure:
	# fix for compiler with broken namespace
	${REINPLACE_CMD} -e 's|\([(! 	]\)log\([)+ 	]\)|\1dolog\2|g' \
		${WRKSRC}/server/msgidd.c
	${REINPLACE_CMD} ${ALONE} \
		-e "s=/usr/local/news/lib/bin/config=${NEWSBIN}/config=" \
		-e "s=/usr/local/news/cnewsbin=${NEWSBIN}=" \
		-e "s=/usr/local/news/lib=${NEWSCTL}=" \
		-e "s=/var/news/over.view=${NEWSOV}=" \
		-e "s=/var/news=${NEWSARTS}=" \
		-e "s=/usr/local/bin=${PREFIX}/bin=" \
		-e "s=/usr/local/sbin=${PREFIX}/sbin=" \
		-e "s=/usr/local/man=${PREFIX}/man=" \
		${WRKSRC}/conf.h

pre-install:
	${MKDIR} ${STAGEDIR}${NEWSBIN}

post-install:
	${MKDIR} ${STAGEDIR}${NEWSCTL}
	${INSTALL_DATA} ${WRKSRC}/overview.fmt ${STAGEDIR}${NEWSCTL}/overview.fmt

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSFILES1:S=^=${WRKSRC}/=} ${STAGEDIR}${DOCSDIR}/
.for i in ${DOCSFILES2}
	${INSTALL_DATA} ${WRKSRC}/${i}/README ${STAGEDIR}${DOCSDIR}/${i}-README
.endfor

.include <bsd.port.mk>
