# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	zenphoto
PORTVERSION=	1.4.5
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/archive/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simpler web photo gallery

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

NO_BUILD=	yes
USE_PHP=	gd gettext json mbstring mysql pcre session
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION}

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME}

NO_STAGE=	yes
post-extract:
	@${RM} ${WRKSRC}/doc_files/Zenphoto\ license.txt ${WRKSRC}/doc_files/README.html ${WRKSRC}/zp-core/Zenphoto.package

do-install:
	${MKDIR} ${WWWDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

# maintainer section:

MS_DIRRMTRY=	albums cache themes zp-core
MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	cd ${WRKSRC}/ && \
		${MKDIR} ${MS_DIRRMTRY} && \
		${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' > ${MS_PLIST} && \
		${FIND} -s * -type d | ${TAIL} -r | ${SED} 's|^|@dirrm %%WWWDIR%%/|' >> ${MS_PLIST} && \
		${ECHO} '@dirrmtry %%WWWDIR%%' >> ${MS_PLIST}
.for dir in ${MS_DIRRMTRY}
	${REINPLACE_CMD} '/^@dirrm %%WWWDIR%%\/${dir:C/\//\\\//g}$$/ s|@dirrm|&try|' ${MS_PLIST}
.endfor
	${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
