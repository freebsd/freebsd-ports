# New ports collection makefile for:	kbtv
# Date created:				Tue Oct  4 01:59:31 UTC 2005
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	kbtv
DISTVERSION=	1.2.4
PORTREVISION=	5
CATEGORIES=	multimedia python kde kld
MASTER_SITES=	SF \
		http://freebsd.ricin.com/ports/distfiles/
EXTRACT_SUFX=	.tbz

MAINTAINER=	danny@ricin.com
COMMENT=	KDE TV viewer for FreeBSD

RUN_DEPENDS=	kdepyuic:${PORTSDIR}/x11-toolkits/py-kde
BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13 \
		kdepyuic:${PORTSDIR}/x11-toolkits/py-kde

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_PYTHON=	yes
USE_SDL=	sdl
INSTALLS_ICONS=	yes

OPTIONS=	PWC                   "Philips and compatible cameras" off \
		SAA                   "Philips SAA713x TV cards" off \
		SAA_TUNER_PHILIPS     "SAA with Philips tuner API" on \
		SAA_TUNER_PHILIPS_MK3 "SAA with Philips MK3 tuner API" off \
		SAA_TUNER_ALPS        "SAA with Alps tuner API" off \
		SAA_TUNER_LG          "SAA with LG tuner API" off \
		SAA_TUNER_TEMIC       "SAA with Temic tuner API" off \
		SAA_STD_PAL_B_G       "SAA with PAL B/G standard" on \
		SAA_STD_PAL_I         "SAA with PAL I standard" off \
		SAA_STD_PAL_D_K       "SAA with PAL D/K standard" off \
		SAA_STD_PAL_L         "SAA with PAL L standard" off \
		SAA_STD_PAL_LACCENT   "SAA with PAL L' standard" off \
		SAA_STD_NTSC          "SAA with NTSC N/M standard" off \
		SAA_STD_NTSC_JAPAN    "SAA with NTSC Japan standard" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700000
BROKEN=		does not build on 7.x and greater
.endif

.if defined(WITH_PWC)
.if !exists(/usr/src/sys/Makefile)
IGNORE=		kernel sources required for pwc
.endif
PLIST_SUB+=	PWC=""
RUN_DEPENDS+=	/boot/modules/pwc.ko:${PORTSDIR}/multimedia/pwcbsd
.else
PLIST_SUB+=	PWC="@comment "
.endif

.if defined(WITH_SAA)
.if !exists(/usr/src/sys/Makefile)
IGNORE=		kernel sources required for saa
.endif
PLIST_SUB+=	SAA=""
.else
PLIST_SUB+=	SAA="@comment "
.endif

.if defined(WITH_PWC) || defined(WITH_SAA)
NO_PACKAGE=	port requires building against local kernel sources
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|FROMPORT = False|FROMPORT = True|' \
		${WRKSRC}/installprefs.py
	@${REINPLACE_CMD} -e 's|sdl11-config|${SDL_CONFIG}|g' \
		${WRKSRC}/do_build.py ${WRKSRC}/do_configure.py
.if defined(WITH_PWC)
	@${REINPLACE_CMD} -e 's|WITH_PWC = False|WITH_PWC = True|' \
		${WRKSRC}/buildprefs.py
.endif
.if defined(WITH_SAA)
	@${REINPLACE_CMD} -e 's|WITH_SAA = False|WITH_SAA = True|' \
		${WRKSRC}/buildprefs.py
.if defined(WITHOUT_SAA_TUNER_PHILIPS)
.if defined(WITH_SAA_TUNER_PHILIPS_MK3)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER = SAA_TUNER_PHILIPS|SAA_TUNER = SAA_TUNER_PHILIPS_MK3|' \
		${WRKSRC}/buildprefs.py
.elif defined(WITH_SAA_TUNER_ALPS)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER = SAA_TUNER_PHILIPS|SAA_TUNER = SAA_TUNER_ALPS|' \
		${WRKSRC}/buildprefs.py
.elif defined(WITH_SAA_TUNER_LG)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER = SAA_TUNER_PHILIPS|SAA_TUNER = SAA_TUNER_LG|' \
		${WRKSRC}/buildprefs.py
.elif defined(WITH_SAA_TUNER_TEMIC)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER = SAA_TUNER_PHILIPS|SAA_TUNER = SAA_TUNER_TEMIC|' \
		${WRKSRC}/buildprefs.py
.endif
.endif
.if defined(WITHOUT_SAA_STD_PAL_B_G)
.if defined(WITH_SAA_STD_PAL_I)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER_STD = SAA_TUNER_STD_PAL_B_G|SAA_TUNER_STD = SAA_TUNER_STD_PAL_I|' \
		${WRKSRC}/buildprefs.py
.elif defined(WITH_SAA_STD_PAL_D_K)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER_STD = SAA_TUNER_STD_PAL_B_G|SAA_TUNER_STD = SAA_TUNER_STD_PAL_D_K|' \
		${WRKSRC}/buildprefs.py
.elif defined(WITH_SAA_STD_PAL_L)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER_STD = SAA_TUNER_STD_PAL_B_G|SAA_TUNER_STD = SAA_TUNER_STD_PAL_L|' \
		${WRKSRC}/buildprefs.py
.elif defined(WITH_SAA_STD_PAL_LACCENT)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER_STD = SAA_TUNER_STD_PAL_B_G|SAA_TUNER_STD = SAA_TUNER_STD_PAL_LACCENT|' \
		${WRKSRC}/buildprefs.py
.elif defined(WITH_SAA_STD_NTSC)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER_STD = SAA_TUNER_STD_PAL_B_G|SAA_TUNER_STD = SAA_TUNER_STD_NTSC|' \
		${WRKSRC}/buildprefs.py
.elif defined(WITH_SAA_STD_NTSC_JAPAN)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER_STD = SAA_TUNER_STD_PAL_B_G|SAA_TUNER_STD = SAA_TUNER_STD_NTSC_JAPAN|' \
		${WRKSRC}/buildprefs.py
.endif
.endif
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|"freebsd7"|"freebsd7", "freebsd8"|' ${WRKSRC}/do_configure.py

do-configure:
	@cd ${WRKSRC} && ${MAKE} configure

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${MKDIR} ${DOCSDIR} && \
	    ${INSTALL_DATA} README NEWS ${DOCSDIR} && \
	    ${ECHO} "README -> ${DOCSDIR}/README" && \
	    ${ECHO} "NEWS -> ${DOCSDIR}/NEWS"
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
