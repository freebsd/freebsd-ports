# New ports collection makefile for:	openvanilla-modules
# Date Created:				3 September 2005
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	openvanilla-modules
PORTVERSION=	0.7.2.b20060214
CATEGORIES=	textproc
MASTER_SITES=	http://www.csie.org/~llwang/	\
		http://www.infor.org/~llwang/
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	Input method modules for OpenVanilla

BUILD_DEPENDS=	${X11BASE}/include/OpenVanilla/OpenVanilla.h:${PORTSDIR}/textproc/openvanilla-framework
RUN_DEPENDS=	${X11BASE}/lib/scim-1.0/IMEngine/OVLoader-SCIM.so:${PORTSDIR}/textproc/scim-openvanilla

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15:env
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

OPTIONS=	OVIMArray		"Array Input Module"		on \
		OVIMBig5		"Big5 Input Module"		off \
		OVIMGeneric		"Generic Input Module"		on \
		OVIMPOJ_Holo		"POJ-Holo Input Module"		on \
		OVIMPhonetic		"Phonetic Input Module"		on \
		OVIMRoman		"Roman Input Module"		off \
		OVIMTibetan		"Tibetan Input Module"		off \
		OVIMUnicode		"Unicode Input Module"		off

MAKE_ARGS+=	INSTALL_PREFIX=${PREFIX} OV_INCLUDE=${X11BASE}/include

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OVIMArray)
PLIST_SUB+=	OVIMArray=""
.else
PLIST_SUB+=	OVIMArray="@comment "
.endif
.if defined(WITH_OVIMBig5)
PLIST_SUB+=	OVIMBig5=""
.else
PLIST_SUB+=	OVIMBig5="@comment "
.endif
.if !defined(WITHOUT_OVIMGeneric)
PLIST_SUB+=	OVIMGeneric=""
.else
PLIST_SUB+=	OVIMGeneric="@comment "
.endif
.if !defined(WITHOUT_OVIMPOJ_Holo)
PLIST_SUB+=	OVIMPOJ_Holo=""
.else
PLIST_SUB+=	OVIMPOJ_Holo="@comment "
.endif
.if !defined(WITHOUT_OVIMPhonetic)
PLIST_SUB+=	OVIMPhonetic=""
.else
PLIST_SUB+=	OVIMPhonetic="@comment "
.endif
.if defined(WITH_OVIMRoman)
PLIST_SUB+=	OVIMRoman=""
.else
PLIST_SUB+=	OVIMRoman="@comment "
.endif
.if defined(WITH_OVIMTibetan)
PLIST_SUB+=	OVIMTibetan=""
.else
PLIST_SUB+=	OVIMTibetan="@comment "
.endif
.if defined(WITH_OVIMUnicode)
PLIST_SUB+=	OVIMUnicode=""
.else
PLIST_SUB+=	OVIMUnicode="@comment "
.endif

do-build:
.if !defined(WITHOUT_OVIMArray)
	@(cd ${WRKSRC}/Modules/OVIMArray; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if defined(WITH_OVIMBig5)
	@(cd ${WRKSRC}/Modules/OVIMBig5; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if !defined(WITHOUT_OVIMGeneric)
	@(cd ${WRKSRC}/Modules/OVIMGeneric; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if !defined(WITHOUT_OVIMPOJ_Holo)
	@(cd ${WRKSRC}/Modules/OVIMPOJ-Holo; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if !defined(WITHOUT_OVIMPhonetic)
	@(cd ${WRKSRC}/Modules/OVIMPhonetic; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if defined(WITH_OVIMRoman)
	@(cd ${WRKSRC}/Modules/OVIMRoman; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if !defined(WITHOUT_OVIMTibetan)
	@(cd ${WRKSRC}/Modules/OVIMTibetan; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if defined(WITH_OVIMUnicode)
	@(cd ${WRKSRC}/Modules/OVIMUnicode; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif

do-install:
.if !defined(WITHOUT_OVIMArray)
	@(cd ${WRKSRC}/Modules/OVIMArray; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if defined(WITH_OVIMBig5)
	@(cd ${WRKSRC}/Modules/OVIMBig5; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if !defined(WITHOUT_OVIMGeneric)
	@(cd ${WRKSRC}/Modules/OVIMGeneric; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if !defined(WITHOUT_OVIMPOJ_Holo)
	@(cd ${WRKSRC}/Modules/OVIMPOJ-Holo; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if !defined(WITHOUT_OVIMPhonetic)
	@(cd ${WRKSRC}/Modules/OVIMPhonetic; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if defined(WITH_OVIMRoman)
	@(cd ${WRKSRC}/Modules/OVIMRoman; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if !defined(WITHOUT_OVIMTibetan)
	@(cd ${WRKSRC}/Modules/OVIMTibetan; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if defined(WITH_OVIMUnicode)
	@(cd ${WRKSRC}/Modules/OVIMUnicode; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif

.include <bsd.port.post.mk>
