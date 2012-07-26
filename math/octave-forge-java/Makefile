# New ports collection makefile for:	octave-forge-java
# Date created:		19 June 2012
# Whom:			Stephen Montgomery-Smith <stephen@FreeBSD.org>
#
# $FreeBSD$
#

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
JAVA_VERSION=	1.5+
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src
MAKE_ENV+=	MKOCTFILE=mkoctfile

RUN_DEPENDS+=	${TARBALLS_DIR}/signal.tar.gz:${PORTSDIR}/math/octave-forge-signal

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
post-patch:
	${REINPLACE_CMD} 's+/client/libjvm.so+/server/libjvm.so+' ${WRKSRC}/__java__.cc
	${REINPLACE_CMD} 's|getenv ("JAVA_HOME")|"${JAVA_HOME}"|' ${WRKDIR}/java/pre_install.m

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.post.mk>
