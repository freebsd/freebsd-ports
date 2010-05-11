# New ports collection Makefile for:	soprano
# Date created:				2008-01-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	soprano
PORTVERSION=	2.4.3
CATEGORIES?=	textproc
MASTER_SITES=	SF/${PORTNAME}/Soprano/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QT4 RDF framework

LIB_DEPENDS=	clucene.0:${PORTSDIR}/textproc/clucene \
		raptor.3:${PORTSDIR}/textproc/raptor

#OPTIONS+=	REDLAND "Use Redland as storage backend (required for KDE4)" on
#OPTIONS+=	VIRTUOSO "Use libiodbc/virtuoso as storage backend (required for KDE4)" on
OPTIONS+=	SESAME2 "Use Sesame2 as storage backend (requires Java)" off

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus qtestlib network \
		qmake_build moc_build uic_build rcc_build
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_CMAKE=	yes

.include <bsd.port.options.mk>

.if !defined(WITHOUT_REDLAND)
LIB_DEPENDS+=	rdf.0:${PORTSDIR}/textproc/redland
PLIST_SUB+=	REDLAND=""
.else
CMAKE_ARGS+=	-DSOPRANO_DISABLE_REDLAND_BACKEND=yes
PLIST_SUB+=	REDLAND="@comment "
.endif

.if !defined(WITHOUT_VIRTUOSO)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
PLIST_SUB+=	VIRTUOSO=""
.else
CMAKE_ARGS+=	-DSOPRANO_DISABLE_VIRTUOSO_BACKEND=yes
PLIST_SUB+=	VIRTUOSO="@comment "
.endif

.if defined(WITH_SESAME2)
CATEGORIES+=	java
CMAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
PLIST_SUB+=	SESAME2=""
.else
CMAKE_ARGS+=	-DSOPRANO_DISABLE_SESAME2_BACKEND=yes
PLIST_SUB+=	SESAME2="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -E -e "s,$${LIB_SUFFIX}/pkgconfig,data/pkgconfig," \
		-e 's,VERSION STR(LESS|EQUAL|GREATER) "([^"]+)",VERSION VERSION_\1 \2,g' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e "s,soprano/cmake,cmake/Modules," \
		${WRKSRC}/cmake/modules/CMakeLists.txt

post-install:
.if defined(WITH_VIRTUOSO)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
