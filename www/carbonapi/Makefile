# $FreeBSD$

PORTNAME=		carbonapi
DISTVERSION=		0.11.0
CATEGORIES=		www

MAINTAINER=		a.andersson.thn@gmail.com
COMMENT=		Go implementation of carbonapi

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		go>=1.8:lang/go

USES=			gmake

USE_GITHUB=		yes
GH_ACCOUNT=		go-graphite
GH_SUBDIR=		src/github.com/${GH_ACCOUNT}/${PORTNAME}
USE_RC_SUBR=		${PORTNAME}

USERS=			carbon
GROUPS=			carbon

OPTIONS_DEFINE=		CAIRO

CAIRO_USES=		pkgconfig
CAIRO_VARS=		CARBON_API_ARGS=${PORTNAME}
CAIRO_VARS_OFF=		CARBON_API_ARGS=nocairo
CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} VERSION=${DISTVERSION} \
		${MAKE_CMD} ${CARBON_API_ARGS}

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/carbonapi
	@${MKDIR} ${STAGEDIR}/var/log/carbonapi
	${INSTALL_PROGRAM} ${WRKSRC}/carbonapi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/carbonapi.example.toml ${STAGEDIR}${PREFIX}/etc/carbonapi
	${INSTALL_DATA} ${WRKSRC}/carbonapi.example.yaml ${STAGEDIR}${PREFIX}/etc/carbonapi
	${INSTALL_DATA} ${WRKSRC}/graphiteWeb.example.yaml ${STAGEDIR}${PREFIX}/etc/carbonapi
	${INSTALL_DATA} ${WRKSRC}/graphTemplates.example.toml ${STAGEDIR}${PREFIX}/etc/carbonapi
	${INSTALL_DATA} ${WRKSRC}/graphTemplates.example.yaml ${STAGEDIR}${PREFIX}/etc/carbonapi

.include <bsd.port.mk>
