# New ports collection makefile for:	RKWard
# Date created:        19 April 2006
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	rkward
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/Current_Stable_Releases
PKGNAMESUFFIX=	-kde4

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	IDE/GUI for the R-project

LIB_DEPENDS=	R.0:${PORTSDIR}/math/R
RUN_DEPENDS=	seq2:${PORTSDIR}/misc/seq2

LICENSE=	GPLv2

CONFLICTS=	rkward-0.4.*

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build phonon

USE_KDE4=	kdehier kdeprefix automoc4 kdelibs
USE_PHP=	yes
WANT_PHP_CLI=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
INSTALLS_ICONS=	yes

DOCSDIR=	${PREFIX}/share/doc/HTML/en/rkward

.if defined(WITHOUT_NLS)
NLS=		"@comment "
.else
NLS=		""
.endif
PLIST_SUB+=	NLS=${NLS}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
.endif

PHP2FIX=	rkward/settings/rksettingsmodulephp.cpp

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/bin/php|${LOCALBASE}/bin/php|'	\
		${PHP2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'	\
		${WRKSRC}/rkward/rkward.sh.template
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(doc)|#ADD_SUBDIRECTORY(doc)|'	\
		${WRKSRC}/CMakeLists.txt
.else
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1-Based Variant V1.0,V4.2-Based Variant V1.1,g' \
		${WRKSRC}/doc/rkward/index.docbook
.endif
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(po)|#ADD_SUBDIRECTORY(po)|'	\
		${WRKSRC}/CMakeLists.txt
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
	@${ECHO_MSG} "To pass the tests, somme CRAN packages like R2HTML"
	@${ECHO_MSG} "must be installed."
	(cd ${WRKSRC}/tests && make plugintests)
.endif

.include <bsd.port.mk>
