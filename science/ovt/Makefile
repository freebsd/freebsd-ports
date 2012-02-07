# New ports collection makefile for:   ovt
# Date created:                16 Sept 2003
# Whom:                        Mykola Khotyaintsev <ko@nest.irfu.se>
#
# $FreeBSD$
#

PORTNAME=	ovt
PORTVERSION=	2.3
PORTREVISION=	8
CATEGORIES=	science astro java
MASTER_SITES=	http://ovt.irfu.se/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}_${OVTBUILD}-src

MAINTAINER=	yuri@irfu.se
COMMENT=	The Orbit Visualization Tool

LIB_DEPENDS=	vtkCommonJava:${PORTSDIR}/math/vtk-java

WRKSRC=		${WRKDIR}/${PORTNAME}2g
OVTBUILD=	4
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native

CONFIGURE_ARGS=	--with-jdk=${JAVA_HOME}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
