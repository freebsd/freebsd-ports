# $FreeBSD$

PORTNAME=	coturn
DISTVERSION=	4.5.2
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TURN server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent_core.so:devel/libevent

USES=		gettext-runtime gmake mysql pkgconfig shebangfix sqlite ssl
USE_GITHUB=	yes

SHEBANG_FILES=	examples/scripts/oauth.sh examples/scripts/restapi/shared_secret_maintainer.pl

USE_RC_SUBR=	turnserver

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-shared --turndbdir=/var/db/${PORTNAME}

DOCSDIR=	${PREFIX}/share/doc/turnserver
EXAMPLESDIR=	${PREFIX}/share/examples/turnserver

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
