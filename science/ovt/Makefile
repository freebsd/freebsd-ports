# New ports collection makefile for:   ovt
# Date created:                16 Sept 2003
# Whom:                        Mykola Khotyaintsev <ko@nest.irfu.se>
#
# $FreeBSD$
#

PORTNAME=	ovt
PORTVERSION=	2.3
CATEGORIES=	science astro
MASTER_SITES=	# http://ovt.irfu.se/download/
DISTNAME=	${PKGNAME}_${OVTBUILD}-src

MAINTAINER=	ko@nest.irfu.se
COMMENT=	The Orbit Visualization Tool

LIB_DEPENDS=	vtkCommonJava:${PORTSDIR}/math/vtk-java

WRKSRC=		${WRKDIR}/${PKGNAME}
OVTBUILD=	3
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
#USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386

USE_JAVA=	1.4
NEED_JAVAC=	yes
USE_JIKES=	no

CONFIGURE_ARGS=	--with-jdk=${_JAVA_HOME_FREEBSD_1_4} --without-jikes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

RESTRICTED=	yes

.include <bsd.port.pre.mk>

# Check for OVT distfile
.if !exists(${DISTDIR}/${DISTFILES}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access http://ovt.irfu.se/download/ with a web browser and\n\
follow the \"Download\" link for the \"OVT ${PORTVERSION} Sources\".\n\
You will be required to log in and register, but you can create an account\n\
on this page.  After registration download the source file, ${DISTFILES}.\n\
Please place this file in ${DISTDIR}.\n
.endif

.include <bsd.port.post.mk>
