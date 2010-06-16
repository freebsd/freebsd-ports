# New ports collection makefile for:	openvanilla-modules
# Date Created:				3 September 2005
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	openvanilla-modules
PORTVERSION=	0.7.2.20070514
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rafan
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Input method modules for OpenVanilla

BUILD_DEPENDS=	${LOCALBASE}/include/OpenVanilla/OpenVanilla.h:${PORTSDIR}/textproc/openvanilla-framework
RUN_DEPENDS=	${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/OVLoader-SCIM.so:${PORTSDIR}/textproc/scim-openvanilla

USE_AUTOTOOLS=	libtool:22:env
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

OPTIONS=	OVIMArray		"Array Input Module"		on \
		OVIMBig5		"Big5 Input Module"		off \
		OVIMGeneric		"Generic Input Module"		on \
		OVIMPOJ_Holo		"POJ-Holo Input Module"		on \
		OVIMPhonetic		"Phonetic Input Module"		on \
		OVIMRoman		"Roman Input Module"		off \
		OVIMSpaceChewing	"Chewing Input Module"		on \
		OVIMTibetan		"Tibetan Input Module"		off \
		OVIMUnicode		"Unicode Input Module"		off

MAKE_ARGS+=	INSTALL_PREFIX=${PREFIX} OV_INCLUDE=${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800501
BROKEN=		does not build
.endif

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
#.if defined(WITH_OVIMBoshiamy)
#PLIST_SUB+=	OVIMBoshiamy=""
#.else
#PLIST_SUB+=	OVIMBoshiamy="@comment "
#.endif
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
.if !defined(WITHOUT_OVIMSpaceChewing)
PLIST_SUB+=	OVIMSpaceChewing=""
.else
PLIST_SUB+=	OVIMSpaceChewing="@comment "
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

#.if defined(WITH_OVIMBoshiamy)
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

#.if !defined(WITHOUT_OVIMSpaceChewing)
#LIB_DEPENDS+=	chewing.3:${PORTSDIR}/chinese/libchewing
#.endif

do-build:
.if !defined(WITHOUT_OVIMArray)
	@(cd ${WRKSRC}/Modules/OVIMArray; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if defined(WITH_OVIMBig5)
	@(cd ${WRKSRC}/Modules/OVIMBig5; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
#.if defined(WITH_OVIMBoshiamy)
#	@(cd ${WRKSRC}/Modules/OVIMBoshiamy; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
#.endif
.if !defined(WITHOUT_OVIMGeneric)
	@(cd ${WRKSRC}/Modules/OVIMGeneric; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if !defined(WITHOUT_OVIMPOJ_Holo)
	@(cd ${WRKSRC}/Modules/OVIMPOJ-Holo; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if !defined(WITHOUT_OVIMPhonetic)
	@(cd ${WRKSRC}/Modules/OVIMPhonetic; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if !defined(WITHOUT_OVIMSpaceChewing)
	@(cd ${WRKSRC}/Modules/OVIMSpaceChewing0.3; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} data all)
.endif
.if defined(WITH_OVIMRoman)
	@(cd ${WRKSRC}/Modules/OVIMRoman; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all)
.endif
.if defined(WITH_OVIMTibetan)
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
#.if defined(WITH_OVIMBoshiamy)
#	@(cd ${WRKSRC}/Modules/OVIMBoshiamy; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
#.endif
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
.if !defined(WITHOUT_OVIMSpaceChewing)
	@(cd ${WRKSRC}/Modules/OVIMSpaceChewing0.3; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if defined(WITH_OVIMTibetan)
	@(cd ${WRKSRC}/Modules/OVIMTibetan; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif
.if defined(WITH_OVIMUnicode)
	@(cd ${WRKSRC}/Modules/OVIMUnicode; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install)
.endif

.include <bsd.port.post.mk>
