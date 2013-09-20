# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	mpiexec
PORTVERSION=	0.84
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.osc.edu/~djohnson/mpiexec/
EXTRACT_SUFX=	.tgz

MAINTAINER=	5u623l20@gmail.com
COMMENT=	A tool to run a parallel job from within a PBS environment

LIB_DEPENDS=	torque.2:${PORTSDIR}/sysutils/torque

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-default-comm=mpich2

PLIST_FILES=	bin/mpiexec
MAN1=		mpiexec.1

CONFLICTS=	mpich2-1.2.*

NO_STAGE=	yes
.include <bsd.port.mk>
