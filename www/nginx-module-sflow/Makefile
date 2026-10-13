PORTNAME=	nginx-module-sflow
DISTVERSION=	0.9.12
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the sflow module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-sflow-module

LICENSE=	BSD2CLAUSE InMon
LICENSE_COMB=	multi
LICENSE_NAME_InMon=	InMon sFlow licence
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_InMon=	${WRKSRC}/LICENSE
LICENSE_PERMS_InMon=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-sflow-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/ngx_http_sflow.h \
		src/ngx_http_sflow_api.c \
		src/ngx_http_sflow_api.h \
		src/ngx_http_sflow_config.c \
		src/ngx_http_sflow_config.h \
		src/ngx_http_sflow_module.c

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
