# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	openvanilla-modules
PORTVERSION=	0.7.2.20070514
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rafan
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Input method modules for OpenVanilla

BUILD_DEPENDS=	${LOCALBASE}/include/OpenVanilla/OpenVanilla.h:${PORTSDIR}/textproc/openvanilla-framework
RUN_DEPENDS=	${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.so:${PORTSDIR}/textproc/scim-openvanilla

USES=		perl5
USE_AUTOTOOLS=	libtool:env
USE_GMAKE=	yes
USE_PERL5=	build

OPTIONS_DEFINE=		OVIMArray OVIMBig5 OVIMGeneric OVIMPOJ_Holo OVIMPhonetic OVIMRoman \
			OVIMSpaceChewing OVIMTibetan OVIMUnicode
OPTIONS_DEFAULT=	OVIMArray OVIMGeneric OVIMPOJ_Holo OVIMPhonetic OVIMSpaceChewing
OVIMArray_DESC=		Array Input Module
OVIMBig5_DESC=		Big5 Input Module
OVIMGeneric_DESC=	Generic Input Module
OVIMPOJ_Holo_DESC=	POJ-Holo Input Module
OVIMPhonetic_DESC=	Phonetic Input Module
OVIMRoman_DESC=		Roman Input Module
OVIMSpaceChewing_DESC=	Chewing Input Module
OVIMTibetan_DESC=	Tibetan Input Module
OVIMUnicode_DESC=	Unicode Input Module

MAKE_ARGS+=	INSTALL_PREFIX=${PREFIX} OV_INCLUDE=${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.options.mk>

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Modules-SharedSource-OVCINInfo.cpp

.if ${PORT_OPTIONS:MOVIMArray}
PLIST_SUB+=	OVIMArray=""
.else
PLIST_SUB+=	OVIMArray="@comment "
.endif
.if ${PORT_OPTIONS:MOVIMBig5}
PLIST_SUB+=	OVIMBig5=""
.else
PLIST_SUB+=	OVIMBig5="@comment "
.endif
#.if ${PORT_OPTIONS:MOVIMBoshiamy}
#PLIST_SUB+=	OVIMBoshiamy=""
#.else
#PLIST_SUB+=	OVIMBoshiamy="@comment "
#.endif
.if ${PORT_OPTIONS:MOVIMGeneric}
PLIST_SUB+=	OVIMGeneric=""
.else
PLIST_SUB+=	OVIMGeneric="@comment "
.endif
.if ${PORT_OPTIONS:MOVIMPOJ_Holo}
PLIST_SUB+=	OVIMPOJ_Holo=""
.else
PLIST_SUB+=	OVIMPOJ_Holo="@comment "
.endif
.if ${PORT_OPTIONS:MOVIMPhonetic}
PLIST_SUB+=	OVIMPhonetic=""
.else
PLIST_SUB+=	OVIMPhonetic="@comment "
.endif
.if ${PORT_OPTIONS:MOVIMRoman}
PLIST_SUB+=	OVIMRoman=""
.else
PLIST_SUB+=	OVIMRoman="@comment "
.endif
.if ${PORT_OPTIONS:MOVIMSpaceChewing}
PLIST_SUB+=	OVIMSpaceChewing=""
.else
PLIST_SUB+=	OVIMSpaceChewing="@comment "
.endif
.if ${PORT_OPTIONS:MOVIMTibetan}
PLIST_SUB+=	OVIMTibetan=""
.else
PLIST_SUB+=	OVIMTibetan="@comment "
.endif
.if ${PORT_OPTIONS:MOVIMUnicode}
PLIST_SUB+=	OVIMUnicode=""
.else
PLIST_SUB+=	OVIMUnicode="@comment "
.endif

#.if ${PORT_OPTIONS:MOVIMBoshiamy}
#DISTFILES+=	liu5.cin
#NOFETCHFILES=	liu5.cin
#EXTRACT_ONLY+=	openvanilla-${PORTVERSION}${EXTRACT_SUFX}
#LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
#LDFLAGS+=	${LOCALBASE}/lib
#.if !exists(${DISTDIR}/liu5.cin)
#IGNORE=		need liu5.cin from a legal copy of LIU57 standard version CDROM to use Boshiamy input module. Please copy /UNIX/xcin2.5/liu5.cin from the CDROM to ${DISTDIR} and run make again
#.endif
#post-extract:
#	@${CP} ${DISTDIR}/liu5.cin ${WRKSRC}/Modules/OVIMBoshiamy
#.endif

#.if ${PORT_OPTIONS:MOVIMSpaceChewing}
#LIB_DEPENDS+=	chewing.3:${PORTSDIR}/chinese/libchewing
#.endif

do-build:
.if ${PORT_OPTIONS:MOVIMArray}
	@(cd ${WRKSRC}/Modules/OVIMArray; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if ${PORT_OPTIONS:MOVIMBig5}
	@(cd ${WRKSRC}/Modules/OVIMBig5; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
#.if ${PORT_OPTIONS:MOVIMBoshiamy}
#	@(cd ${WRKSRC}/Modules/OVIMBoshiamy; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
#.endif
.if ${PORT_OPTIONS:MOVIMGeneric}
	@(cd ${WRKSRC}/Modules/OVIMGeneric; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if ${PORT_OPTIONS:MOVIMPOJ_Holo}
	@(cd ${WRKSRC}/Modules/OVIMPOJ-Holo; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if ${PORT_OPTIONS:MOVIMPhonetic}
	@(cd ${WRKSRC}/Modules/OVIMPhonetic; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if ${PORT_OPTIONS:MOVIMSpaceChewing}
	@(cd ${WRKSRC}/Modules/OVIMSpaceChewing0.3; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} data all)
.endif
.if ${PORT_OPTIONS:MOVIMRoman}
	@(cd ${WRKSRC}/Modules/OVIMRoman; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if ${PORT_OPTIONS:MOVIMTibetan}
	@(cd ${WRKSRC}/Modules/OVIMTibetan; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if ${PORT_OPTIONS:MOVIMUnicode}
	@(cd ${WRKSRC}/Modules/OVIMUnicode; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif

do-install:
.if ${PORT_OPTIONS:MOVIMArray}
	@(cd ${WRKSRC}/Modules/OVIMArray; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if ${PORT_OPTIONS:MOVIMBig5}
	@(cd ${WRKSRC}/Modules/OVIMBig5; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
#.if ${PORT_OPTIONS:MOVIMBoshiamy}
#	@(cd ${WRKSRC}/Modules/OVIMBoshiamy; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
#.endif
.if ${PORT_OPTIONS:MOVIMGeneric}
	@(cd ${WRKSRC}/Modules/OVIMGeneric; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if ${PORT_OPTIONS:MOVIMPOJ_Holo}
	@(cd ${WRKSRC}/Modules/OVIMPOJ-Holo; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if ${PORT_OPTIONS:MOVIMPhonetic}
	@(cd ${WRKSRC}/Modules/OVIMPhonetic; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if ${PORT_OPTIONS:MOVIMRoman}
	@(cd ${WRKSRC}/Modules/OVIMRoman; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if ${PORT_OPTIONS:MOVIMSpaceChewing}
	@(cd ${WRKSRC}/Modules/OVIMSpaceChewing0.3; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if ${PORT_OPTIONS:MOVIMTibetan}
	@(cd ${WRKSRC}/Modules/OVIMTibetan; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if ${PORT_OPTIONS:MOVIMUnicode}
	@(cd ${WRKSRC}/Modules/OVIMUnicode; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif

.include <bsd.port.mk>
