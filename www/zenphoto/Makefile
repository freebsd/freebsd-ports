# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	zenphoto
PORTVERSION=	1.4.3.3
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE \
		http://www.zenphoto.org/files/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A simpler web photo gallery

LICENSE=	GPLv2

NO_BUILD=	yes
USE_PHP=	gd gettext json mbstring mysql pcre session
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME}

EMPTYDIRS=	albums cache cache_html/rss plugins/flag_thumbnail plugins/flvplayer plugins/gd_fonts plugins/imagick_fonts plugins/watermarks uploaded

post-extract:
	@${RM} ${WRKSRC}/doc_files/License.txt ${WRKSRC}/doc_files/README.html ${WRKSRC}/zp-core/Zenphoto.package

do-install:
.for dir in ${EMPTYDIRS}
	${TOUCH} ${WRKSRC}/${dir}/.keepme
.endfor
	${MKDIR} ${WWWDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

# maintainer section:

MS_DIRRMTRY=	albums cache themes zp-core
MS_EMPTYDIRS=	${WRKDIR}/.ms-empty-directories
MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	cd ${WRKSRC}/ && \
		${FIND} -s * -type d -empty | ${XARGS} > ${MS_EMPTYDIRS} && \
		${SED} 's|[^ ]*|&/.keepme|g' ${MS_EMPTYDIRS} | ${XARGS} -J % ${TOUCH} % && \
		${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' > ${MS_PLIST} && \
		${FIND} -s * -type d | ${TAIL} -r | ${SED} 's|^|@dirrm %%WWWDIR%%/|' >> ${MS_PLIST} && \
		${ECHO} '@dirrmtry %%WWWDIR%%' >> ${MS_PLIST}
.for dir in ${MS_DIRRMTRY}
	${REINPLACE_CMD} '/^@dirrm %%WWWDIR%%\/${dir:C/\//\\\//g}$$/ s|@dirrm|&try|' ${MS_PLIST}
.endfor
	${INSTALL} -m 600 ${MS_PLIST} ${PLIST}
	${REINPLACE_CMD} -e "/^EMPTYDIRS=/ s|	.*$$|	`${CAT} ${MS_EMPTYDIRS}`|" ${.CURDIR}/Makefile
	
.include <bsd.port.mk>
