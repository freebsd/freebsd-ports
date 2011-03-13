# New ports collection makefile for:	mpiexec
# Date created:		2006-11-16
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	mpiexec
PORTVERSION=	0.83
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.osc.edu/~djohnson/mpiexec/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to run a parallel job from within a PBS environment

LIB_DEPENDS=	torque.2:${PORTSDIR}/sysutils/torque

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-default-comm=mpich2

PLIST_FILES=	bin/mpiexec
MAN1=		mpiexec.1

CONFLICTS=	mpich2-1.2.*

.include <bsd.port.mk>
