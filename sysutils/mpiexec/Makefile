# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	mpiexec
PORTVERSION=	0.84
CATEGORIES=	sysutils parallel
MASTER_SITES=	https://www.osc.edu/~djohnson/mpiexec/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Tool to run a parallel job from within a PBS environment

LICENSE=	GPLv2

CONFLICTS=	mpich2-1.2.*

LIB_DEPENDS=	libtorque.so:${PORTSDIR}/sysutils/torque

USES=		gmake tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-comm=mpich2

PLIST_FILES=	bin/mpiexec man/man1/mpiexec.1.gz

.include <bsd.port.mk>
