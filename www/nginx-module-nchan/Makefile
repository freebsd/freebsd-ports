PORTNAME=	nginx-module-nchan
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.9
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the nchan module for the NGINX ports
WWW=		https://github.com/slact/nchan

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USE_GITHUB=	yes
GH_ACCOUNT=	slact
GH_PROJECT=	nchan

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODSRC=	src LICENCE

post-extract:
	@${RM} ${WRKSRC}/src/store/redis/hiredis/.travis.yml \
		${WRKSRC}/src/store/redis/hiredis/CHANGELOG.md \
		${WRKSRC}/src/store/redis/hiredis/Makefile \
		${WRKSRC}/src/store/redis/hiredis/README.md
	@${FIND} ${WRKSRC}/src -name '.gitignore' -delete
	@${FIND} ${WRKSRC}/src -name '*.rb' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${_MODSRC}" ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
