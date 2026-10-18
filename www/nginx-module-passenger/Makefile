PORTNAME=	nginx-module-passenger
DISTVERSION=	6.2.0
CATEGORIES=	www ruby
MASTER_SITES=	https://github.com/phusion/passenger/releases/download/release-${DISTVERSION}/ \
		https://s3.amazonaws.com/phusion-passenger/releases/
DISTNAME=	passenger-${DISTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the passenger module for the NGINX ports
WWW=		https://www.phusionpassenger.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	site:https://github.com/phusion/passenger/releases

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODDIRS=	build src/cxx_supportlib src/nginx_module src/ruby_supportlib

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src ${STAGEDIR}${MODULESDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/Rakefile ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${_MODDIRS}" ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
