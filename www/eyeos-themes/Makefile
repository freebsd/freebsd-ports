# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	themes
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.eyelook.org/themes/ CSME/myports/${DIST_SUBDIR}
PKGNAMEPREFIX=	eyeOS-
DISTFILES=	${EYETHEMES:S/$/.zip/}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A themes collection for eyeOS

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		zip

EYEDIR?=	${PREFIX}/www/eyeOS
THEMESDIR=	${EYEDIR}/system/themes

OPTIONS_DEFINE=	Crystal_THEME Executive_THEME Kids_THEME LateBloomer_THEME \
		Mac_THEME Mini_THEME NuoveXT_THEME Nuvola_THEME WaterSide_THEME \
		eyeOSVista_THEME animus_THEME minimal_THEME
OPTIONS_DEFAULT:=	${OPTIONS_DEFINE:M*_THEME}
Crystal_THEME_DESC=	based on the Crystal Open Source icons
Executive_THEME_DESC=	designed specially for Companies
Kids_THEME_DESC=	designed specially for Kids and Schools
LateBloomer_THEME_DESC=	based on the Crystal theme
Mac_THEME_DESC=	based on OSX 2.1 Open Source icons
Mini_THEME_DESC=	with mall icons based on Nuvola icon set
NuoveXT_THEME_DESC=	based on 'NuoveXT' Open Source icons
Nuvola_THEME_DESC=	nspired in the great icons Nuvola
WaterSide_THEME_DESC=	inspired in countryside of Saskatchewan
fromX_THEME_DESC=	based on Tango Icons
eyeOSVista_THEME_DESC=	based on the new Vista style
animus_THEME_DESC=	created by AnimusMedia.com
minimal_THEME_DESC=	based on minimalist art

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.for theme in ${OPTIONS_DEFINE:M*_THEME:S/_THEME//}
.if ${PORT_OPTIONS:M${theme}_THEME}
EYETHEMES+=	${theme}
PLIST_SUB+=	${theme:U}=${THEMESDIR:S,^${PREFIX}/,,}/${theme}
PLIST_SUB+=	D${theme:U}="@dirrm ${THEMESDIR:S,^${PREFIX}/,,}/${theme}"
.else
PLIST_SUB+=	${theme:U}="@comment "
PLIST_SUB+=	D${theme:U}="@comment "
.endif
.endfor

PLIST_SUB+=	EYEDIR=${EYEDIR:S,^${PREFIX}/,,}

post-extract:
	@${FIND} ${WRKSRC} -name \*~ -delete

do-install:
	${INSTALL} -d ${THEMESDIR}/
	${CP} -Rp ${EYETHEMES:S,^,${WRKDIR}/,} ${THEMESDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${THEMESDIR}
	${CHMOD} -R go-w ${THEMESDIR}
	${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${THEMESDIR:S,^${PREFIX}/,,} >> ${TMPPLIST}
	${ECHO_CMD} @exec ${CHMOD} -R go-w %D/${THEMESDIR:S,^${PREFIX}/,,} >> ${TMPPLIST}

# Maintainer section
create-plist: build
	:>${PLIST}
.for theme in ${OPTIONS:M*_THEME:S/_THEME//:O}
	${FIND} -s ${WRKSRC}/${theme} -type f -or -type l | \
		${SED} -e 's#^${WRKSRC}/${theme}#%%${theme:U}%%#' >> ${PLIST}
.endfor
.for theme in ${OPTIONS:M*_THEME:S/_THEME//:O}
	${FIND} -ds ${WRKSRC}/${theme} -type d | \
		${SED} -e 's#^${WRKSRC}/${theme}#%%D${theme:U}%%#' >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrmtry %%EYEDIR%%/system/themes >> ${PLIST}
	${ECHO_CMD} @dirrmtry %%EYEDIR%%/system >> ${PLIST}
	${ECHO_CMD} @dirrmtry %%EYEDIR%% >> ${PLIST}

.include <bsd.port.post.mk>
