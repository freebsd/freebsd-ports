# New ports collection makefile for:	dejagnu
# Date created:		12 October 1996
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	dejagnu
PORTVERSION=	1.4.4
CATEGORIES=	misc tcl84 tk84
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated program/system tester

RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		runtest.1

.include <bsd.port.mk>
