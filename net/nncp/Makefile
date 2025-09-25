PORTNAME=	nncp
DISTVERSION=	8.8.3
CATEGORIES=	net
MASTER_SITES=	http://www.nncpgo.org/download/

MAINTAINER=	stargrave@stargrave.org
COMMENT=	Utilities for secure store-and-forward files, mail, command exchanging
WWW=		http://www.nncpgo.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:1.21,modules,no_targets tar:xz

USE_RC_SUBR=	nncp-caller nncp-daemon nncp-toss

MAKE_ARGS=	INFODIR=${STAGEDIR}${PREFIX}/${INFO_PATH}
MAKE_ENV=	${GO_ENV}
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message pkg-install pkg-deinstall

INFO=		nncp
PORTDOCS=	AUTHORS NEWS NEWS.RU README README.RU THANKS

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/nncp.newsyslog.conf.sample ${STAGEDIR}${PREFIX}/etc/nncp.conf.sample

.include <bsd.port.mk>
