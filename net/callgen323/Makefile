# Ports collection makefile for:	callgen
# Whom:					Jakub Klausa <jacke@bofh.pl>
# Date created:				January 15 2004
#
# $FreeBSD$

PORTNAME=	callgen
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/
DISTNAME=	callgen323_${PORTVERSION}

MAINTAINER=	jacke@bofh.pl
COMMENT=	H.323 Call Generator

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:configure

NOCLEANDEPENDS=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/callgen323
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../../devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}

PLIST_FILES=	bin/callgen323

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.if ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 (shared libraries must be compiled with -fPIC)"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_d/callgen323 ${PREFIX}/bin

.include <bsd.port.post.mk>
