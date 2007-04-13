# New ports collection makefile for:	mpiexec
# Date created:		2006-11-16
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	mpiexec
PORTVERSION=	0.82
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.osc.edu/~pw/mpiexec/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trasz@freebsd.org
COMMENT=	A tool to run a parallel job from within a PBS environment

LIB_DEPENDS=	torque.0:${PORTSDIR}/sysutils/torque

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/mpiexec
MAN1=		mpiexec.1

.include <bsd.port.mk>
