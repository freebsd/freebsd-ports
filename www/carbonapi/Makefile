PORTNAME=	carbonapi
DISTVERSION=	0.14.1
CATEGORIES=	www

MAINTAINER=	a.andersson.thn@gmail.com
COMMENT=	Go implementation of carbonapi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	go-graphite

USE_RC_SUBR=	${PORTNAME}

GO_TARGET=	./cmd/carbonapi \
		./cmd/carbonzipper
GO_BUILDFLAGS=	-v \
		${CARBON_ARGS} \
		-ldflags="-X main.BuildVersion=${DISTVERSION}"

CONFLICTS_INSTALL=	carbonzipper # bin/carbonzipper

USERS=		carbon
GROUPS=		carbon

OPTIONS_DEFINE=	CAIRO EXAMPLES

CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_USES=	pkgconfig
CAIRO_VARS=	CARBON_ARGS="-tags cairo"

post-install:
	@${MKDIR} ${STAGEDIR}/var/log/carbonapi

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cmd/carbonapi/*.toml ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cmd/carbonapi/*.yaml ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cmd/carbonzipper/example.conf ${STAGEDIR}${EXAMPLESDIR}/carbonzipper.example.conf

.include <bsd.port.mk>
