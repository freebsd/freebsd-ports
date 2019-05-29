# $FreeBSD$

PORTNAME=	bredbandskollen
PORTVERSION=	0.20181210
CATEGORIES=	net

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Command line tool to check internet connection speed

LICENSE=	GPLv2

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	dotse
GH_PROJECT=	bbk
GH_TAGNAME=	39b47a1

BUILD_WRKSRC=	${WRKSRC}/src/cli

PLIST_FILES=	bin/bbk_cli \
		bin/bredbandskollen

OPTIONS_DEFINE=	GNUTLS

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_MAKE_ARGS=	GNUTLS=1

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/cli ${STAGEDIR}/${PREFIX}/bin/bbk_cli
	${LN} -sf bbk_cli ${STAGEDIR}/${PREFIX}/bin/bredbandskollen

.include <bsd.port.mk>
