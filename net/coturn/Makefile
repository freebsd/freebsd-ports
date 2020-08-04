# $FreeBSD$

PORTNAME=	coturn
DISTVERSION=	4.5.1.3
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TURN server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent_core.so:devel/libevent

USES=		gettext-runtime gmake mysql shebangfix sqlite ssl
USE_GITHUB=	yes

SHEBANG_FILES=	examples/scripts/oauth.sh examples/scripts/restapi/shared_secret_maintainer.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-shared --turndbdir=/var/db/${PORTNAME}

SUB_FILES=	turnserver-service

DOCSDIR=	${PREFIX}/share/doc/turnserver
EXAMPLESDIR=	${PREFIX}/share/examples/turnserver

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/turnserver-service ${STAGEDIR}${PREFIX}/etc/rc.d/turnserver
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
