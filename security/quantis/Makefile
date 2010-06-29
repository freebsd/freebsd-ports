# New ports collection makefile for:	quantis
# Date created:			10 May 2010
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quantis
DISTVERSION=	v10.06.29
CATEGORIES=	security devel java
MASTER_SITES=	http://www.idquantique.com/files/products/quantis/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access Quantis devices

OPTIONS=	PCI "Enable Quantis PCI support" on \
		USB "Enable Quantis USB support (FreeBSD >= 8.1)" on \
		JAVA "Enable Java support" on \
		COMPAT "Build API v1 compatibility libraries" off \
		TOOL "Build EasyQuantis application" on \
		GUI "Build QT4 GUI for EasyQuantis application" on

LICENSE_COMB=	dual
LICENSE=	BSD GPLv2
LICENSE_FILE=	${WRKSRC}/Quantis-${DISTVERSION}/License.txt

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aqo
USE_CMAKE=	yes
USE_QT_VER=	4
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/Quantis-${DISTVERSION}/Libs-Apps

KMODDIR?=	/boot/modules

PORTDOCS=	*
PORTEXAMPLES=	*

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=Debug
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=		requires FreeBSD >= 7
.endif

.if defined(WITH_PCI)
RUN_DEPENDS+=	${KMODDIR}/quantis.ko:${PORTSDIR}/security/quantis-kmod
.else
CMAKE_ARGS+=	-DDISABLE_QUANTIS_PCI=1
.endif

.if defined(WITHOUT_USB) || ${OSVERSION} < 801000
CMAKE_ARGS+=	-DDISABLE_QUANTIS_USB=1
.endif

.if defined(WITH_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
.else
CMAKE_ARGS+=	-DDISABLE_QUANTIS_JAVA=1
.endif

.if defined(WITH_COMPAT)
CMAKE_ARGS+=	-DENABLE_QUANTIS_COMPAT=1

PLIST_SUB+=	COMPAT=""
.else
PLIST_SUB+=	COMPAT="@comment "
.endif

.if defined(WITH_TOOL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libboost_date_time.a:${PORTSDIR}/devel/boost-libs
CXXFLAGS+=	-I${LOCALBASE}/include

. if defined(WITH_GUI)
QT_COMPONENTS+=	gui moc_build uic_build rcc_build qmake_build
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../*.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../User_Manual.pdf ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/../Samples; ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.if defined(WITH_USB) && ${OSVERSION} >= 801000
	@${MKDIR} ${EXAMPLESDIR}/devd
	${INSTALL_DATA} ${FILESDIR}/quantis.conf ${EXAMPLESDIR}/devd
	@${CAT} ${PKGMESSAGE}
.endif
.endif

.include <bsd.port.post.mk>
