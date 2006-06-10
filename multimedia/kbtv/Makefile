# New ports collection makefile for:	kbtv
# Date created:				Tue Oct  4 01:59:31 UTC 2005
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	kbtv
DISTVERSION=	1.1
CATEGORIES=	multimedia python kde
MASTER_SITES=	http://freebsd.ricin.com/ports/distfiles/
EXTRACT_SUFX=	.tbz

MAINTAINER=	danny@ricin.com
COMMENT=	KDE TV viewer for FreeBSD

RUN_DEPENDS=	kdepyuic:${PORTSDIR}/x11-toolkits/py-kde
BUILD_DEPENDS=	${RUN_DEPENDS} swig:${PORTSDIR}/devel/swig13

USE_BZIP2=	YES
USE_KDELIBS_VER=3
USE_PYTHON=	yes
USE_SDL=	sdl
INSTALLS_ICONS=	yes

OPTIONS=	PWC "Philips & compatible cameras (pwc)" off \
		SAA "Philips SAA713x based TV cards (saa)" off \
		SAA_TUNER_PHILIPS "Philips tuner API" on \
		SAA_TUNER_PHILIPS_MK3 "Philips MK3 tuner API" off \
		SAA_TUNER_ALPS "Alps tuner API" off \
		SAA_TUNER_LG "LG tuner API" off \
		SAA_TUNER_TEMIC "Temic tuner API" off \
		SAA_TUNER_NTSC "NTSC tuner standard (default PAL)" off \
		SAA_TUNER_0xC2 "IIC read address 0xc2 (default 0xc0)" off

.include <bsd.port.pre.mk>

.if defined(WITH_PWC)
.if !exists(/usr/src/sys/Makefile)
IGNORE=		kernel sources required for pwc
.endif
PLIST_SUB+=	PWC=""
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		/boot/modules/pwc.ko:${PORTSDIR}/multimedia/pwcbsd
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
		${WRKSRC}/do_build.py
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
.if defined(WITH_SAA_TUNER_NTSC)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER_STD = SAA_TUNER_STD_PAL|SAA_TUNER_STD = SAA_TUNER_STD_NTSC|' \
		${WRKSRC}/buildprefs.py
.endif
.if defined(WITH_SAA_TUNER_0xC2)
	@${REINPLACE_CMD} -e \
		's|SAA_TUNER_IIC = SAA_IIC_0xC0|SAA_TUNER_IIC = SAA_IIC_0xC2|' \
		${WRKSRC}/buildprefs.py
.endif
.endif
.endif

do-configure:
	@cd ${WRKSRC} && ${MAKE} configure

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${MKDIR} ${DOCSDIR} && \
	    ${INSTALL_DATA} README NEWS ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
