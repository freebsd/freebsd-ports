PORTNAME=	nncp
DISTVERSION=	8.13.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.nncpgo.org/download/

MAINTAINER=	stargrave@stargrave.org
COMMENT=	Utilities for secure store-and-forward files, mail, command exchanging
WWW=		http://www.nncpgo.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules,no_targets tar:xz

USE_RC_SUBR=	nncp-caller nncp-daemon nncp-toss

SUB_FILES=	pkg-message pkg-install pkg-deinstall

INFO=		nncp
PORTDOCS=	AUTHORS NEWS NEWS.RU README README.RU THANKS

OPTIONS_DEFINE=	DOCS

do-build:
	GO=${GO_CMD} ${GO_ENV} GO_CFLAGS="${GO_BUILDFLAGS}" \
		CFGPATH=${PREFIX}/etc/nncp.hjson \
		INFODIR=${STAGEDIR}${PREFIX}/${INFO_PATH} \
		PREFIX=${STAGEDIR}${PREFIX} \
		GOCACHE="${WRKDIR}/.cache" ${WRKSRC}/build

do-install:
	PREFIX=${STAGEDIR}${PREFIX} INFODIR=${STAGEDIR}${PREFIX}/${INFO_PATH} \
		${WRKSRC}/install

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/nncp.newsyslog.conf.sample \
		${STAGEDIR}${PREFIX}/etc/nncp.conf.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
