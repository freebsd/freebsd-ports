# New ports collection makefile for:	eyeOS-themes
# Date created:		2006-04-06
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

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
USE_ZIP=	yes

EYEDIR?=	${PREFIX}/www/eyeOS
THEMESDIR=	${EYEDIR}/system/themes

OPTIONS=	Crystal_THEME "based on the Crystal Open Source icons" On
OPTIONS+=	Executive_THEME "designed specially for Companies" On
OPTIONS+=	Kids_THEME "designed specially for Kids and Schools" On
OPTIONS+=	LateBloomer_THEME "based on the Crystal theme" On
OPTIONS+=	Mac_THEME "based on OSX 2.1 Open Source icons" On
OPTIONS+=	Mini_THEME "with mall icons based on Nuvola icon set" On
OPTIONS+=	NuoveXT_THEME "based on 'NuoveXT' Open Source icons" On
OPTIONS+=	Nuvola_THEME "inspired in the great icons Nuvola" On
OPTIONS+=	WaterSide_THEME "inspired in countryside of Saskatchewan" On
OPTIONS+=	fromX_THEME "based on Tango Icons" On
OPTIONS+=	eyeOSVista_THEME "based on the new Vista style" On
OPTIONS+=	animus_THEME "created by AnimusMedia.com" On
OPTIONS+=	minimal_THEME "based on minimalist art" On

.include <bsd.port.pre.mk>

.for theme in ${OPTIONS:M*_THEME:S/_THEME//}
.ifndef WITHOUT_${theme}_THEME
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
