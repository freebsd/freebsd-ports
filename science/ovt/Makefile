# New ports collection makefile for:   ovt
# Date created:                16 Sept 2003
# Whom:                        Mykola Khotyaintsev <ko@nest.irfu.se>
#
# $FreeBSD$
#

PORTNAME=	ovt
PORTVERSION=	2.3
PORTREVISION=	7
CATEGORIES=	science astro java
MASTER_SITES=	# http://ovt.irfu.se/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}_${OVTBUILD}-src

MAINTAINER=	yuri@irfu.se
COMMENT=	The Orbit Visualization Tool

LIB_DEPENDS=	vtkCommonJava:${PORTSDIR}/math/vtk-java

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
OVTBUILD=	3
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

RESTRICTED=	yes

.include <bsd.port.pre.mk>

# Check for OVT distfile
.if !exists(${DISTDIR}/${DISTNAME}{EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=	because of licensing restrictions, you must fetch the source\
distribution \ manually.  Please access http://ovt.irfu.se/download/ with a\
web browser and follow the "Download" link for the "OVT ${PORTVERSION} Sources.\
You will be required to log in and register, but you can create an account\
on this page.  After registration download the source file, ${DISTFILES}.\
Please place this file in ${DISTDIR}
.endif

.include <bsd.port.post.mk>
