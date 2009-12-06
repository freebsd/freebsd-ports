# New ports collection makefile for: 	u++
# Date created:				5 Dec 2009
# Whom:					bms
#
# $FreeBSD$
#

PORTNAME=	u++
PORTVERSION=	5.7.0
CATEGORIES=	lang
MASTER_SITES=	http://plg.uwaterloo.ca/~usystem/pub/uSystem/
EXTRACT_SUFX=	.sh

MAINTAINER=	bms@FreeBSD.org
COMMENT=	The uSystem uC++ Compiler, a concurrent C++ extension language

EXTRACT_CMD=		${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	-b -e && \
			${TAR} xfz ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz

ONLY_FOR_ARCHS=		i386
ONLY_FOR_ARCHS_REASON=	Has not yet been ported to FreeBSD/amd64

USE_GMAKE=	yes
USE_GCC=	4.2+
MAKE_JOBS_SAFE=	no

CONFIGURE_TARGET=	configure
MAKE_ARGS=		VENDOR=pc OS=freebsd CPU=${MACHINE_ARCH} \
			TVENDOR=pc TOS=freebsd TCPU=${MACHINE_ARCH} \
			MULTI=TRUE \
			CCBUILD=${CXX} \
			CCAPP=${CXX} \
			INSTALLPREFIX="${PREFIX}" \
			INSTALLINCDIR="${PREFIX}/include/u++" \
			INSTALLLIBDIR="${PREFIX}/lib/u++" \
			INSTALLBINDIR="${PREFIX}/bin" \
			INSTALLMANDIR="${PREFIX}/man" \
			INSTALLDOCDIR="${PREFIX}/share/doc"

MAN1=		u++.1

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${GMAKE} ${MAKE_ARGS} ${CONFIGURE_ARGS} ${CONFIGURE_TARGET})

.include <bsd.port.pre.mk>

# u++'s configure target baulks if CXX does not start with g++.
# Force it to be defined this way if USE_GCC did nothing.
.if ${CXX} == "c++"
CXX=	g++
.endif

.include <bsd.port.post.mk>
