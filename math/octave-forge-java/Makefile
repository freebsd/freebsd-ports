# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	octave-forge-java
PORTVERSION=	1.2.9
CATEGORIES=	math java

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${OCTAVE_PKGNAME}

GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src
MAKE_ENV+=	MKOCTFILE=mkoctfile

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

BROKEN=		does not work with openjdk, and will soon be part of octave base

RUN_DEPENDS+=	${TARBALLS_DIR}/signal.tar.gz:${PORTSDIR}/math/octave-forge-signal

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-patch:
	${REINPLACE_CMD} 's+/client/libjvm.so+/server/libjvm.so+' ${WRKSRC}/__java__.cc
	${REINPLACE_CMD} 's|getenv ("JAVA_HOME")|"${JAVA_HOME}"|' ${WRKDIR}/java/pre_install.m

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
