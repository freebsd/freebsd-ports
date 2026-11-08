PORTNAME=	nginx-module-otel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the otel module for the NGINX ports
WWW=		https://github.com/nginx/nginx-otel

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	nginx
GH_PROJECT=	nginx-otel

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/CMakeLists.txt \
		${_MODDIR}/config \
		${_MODDIR}/config.make \
		${_MODDIR}/src/batch_exporter.hpp \
		${_MODDIR}/src/grpc_log.cpp \
		${_MODDIR}/src/grpc_log.hpp \
		${_MODDIR}/src/http_module.cpp \
		${_MODDIR}/src/modules.c \
		${_MODDIR}/src/ngx.hpp \
		${_MODDIR}/src/str_view.hpp \
		${_MODDIR}/src/trace_context.hpp \
		${_MODDIR}/src/trace_service_client.hpp

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/CMakeLists.txt ${WRKSRC}/config \
		${WRKSRC}/config.make ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
