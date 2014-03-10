# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quantis
DISTVERSION=	v13.04.29
CATEGORIES=	security devel java
MASTER_SITES=	http://www.idquantique.com/~download/Quantis/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale
DISTNAME=	Quantis-${DISTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access Quantis devices

LICENSE=	BSD GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/Quantis-${DISTVERSION}/License.txt

OPTIONS_DEFINE=	PCI USB JAVA COMPAT TOOL GUI DOCS EXAMPLES
OPTIONS_DEFAULT=PCI USB JAVA TOOL GUI
NO_OPTIONS_SORT=yes

PCI_DESC=	Enable Quantis PCI support
USB_DESC=	Enable Quantis USB support
JAVA_DESC=	Enable Java support
COMPAT_DESC=	Build API v1 compatibility libraries
TOOL_DESC=	Build EasyQuantis application
GUI_DESC=	Build QT4 GUI for EasyQuantis application

EXTRACT_BEFORE_ARGS=	-aqo
USES=		cmake zip:infozip
USE_QT4=	# empty but required
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/Quantis-${DISTVERSION}/Libs-Apps

KMODDIR?=	/boot/modules

PORTDOCS=	*
PORTEXAMPLES=	*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPCI}
RUN_DEPENDS+=	${KMODDIR}/quantis.ko:${PORTSDIR}/security/quantis-kmod
.else
CMAKE_ARGS+=	-DDISABLE_QUANTIS_PCI=1
.endif

.if ! ${PORT_OPTIONS:MUSB}
CMAKE_ARGS+=	-DDISABLE_QUANTIS_USB=1
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
.else
CMAKE_ARGS+=	-DDISABLE_QUANTIS_JAVA=1
.endif

.if ${PORT_OPTIONS:MCOMPAT}
CMAKE_ARGS+=	-DENABLE_QUANTIS_COMPAT=1

PLIST_SUB+=	COMPAT=""
.else
PLIST_SUB+=	COMPAT="@comment "
.endif

.if ${PORT_OPTIONS:MTOOL}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libboost_date_time.a:${PORTSDIR}/devel/boost-libs
CXXFLAGS+=	-I${LOCALBASE}/include

. if ${PORT_OPTIONS:MGUI}
USE_QT4+=	gui moc_build uic_build rcc_build qmake_build
. else
CMAKE_ARGS+=	-DDISABLE_EASYQUANTIS_GUI=1
. endif

PLIST_SUB+=	TOOL=""
.else
CMAKE_ARGS+=	-DDISABLE_EASYQUANTIS=1

PLIST_SUB+=	TOOL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} '/  if(CMAKE_COMPILER_IS_GNU/s/)/ MATCHES "0")/' \
		${WRKSRC}/CMake/CompilersFlags.cmake

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../*.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../User_Manual.pdf ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/../Samples; ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.if ${PORT_OPTIONS:MUSB} && ${OSVERSION} >= 801000
	@${MKDIR} ${EXAMPLESDIR}/devd
	${INSTALL_DATA} ${FILESDIR}/quantis.conf ${EXAMPLESDIR}/devd
	@${CAT} ${PKGMESSAGE}
.endif
.endif

.include <bsd.port.post.mk>
