# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	zenphoto
PORTVERSION=	1.4.12
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simpler web photo gallery

LICENSE=	GPLv2+

BROKEN_powerpc64=	does not build

NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	gd gettext json mbstring mysqli pcre session
USES=		cpe
WANT_PHP_WEB=	yes

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-deinstall pkg-message

USE_GITHUB=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/cache/
	@${FIND} ${WRKSRC} -name .gitignore -delete
	@${FIND} -s ${WRKSRC}/ -type d -empty | ${XARGS} -I % ${TOUCH} %/.keepme
	@${RM} ${WRKSRC}/doc_files/Zenphoto\ license.txt ${WRKSRC}/doc_files/README.html ${WRKSRC}/zp-core/Zenphoto.package

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

MS_DIR=		albums cache themes zp-core
MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	${ECHO_CMD} '@owner www' > ${MS_PLIST}
	${ECHO_CMD} '@group www' >> ${MS_PLIST}
	cd ${WRKSRC}/ && ${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' >> ${MS_PLIST}
.for dir in ${MS_DIR}
	${ECHO_CMD} '@dir %%WWWDIR%%/${dir}' >> ${MS_PLIST}
.endfor
	${ECHO_CMD} '@dir %%WWWDIR%%' >> ${MS_PLIST}
	${ECHO_CMD} '@owner' >> ${MS_PLIST}
	${ECHO_CMD} '@group' >> ${MS_PLIST}
	${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
