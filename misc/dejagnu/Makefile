# Created by: markm
# $FreeBSD$

PORTNAME=	dejagnu
PORTVERSION=	1.5.1
CATEGORIES=	misc tcl tk
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated program/system tester

LICENSE=	GPLv3

BUILD_DEPENDS=	expect:${PORTSDIR}/lang/expect
RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect

USE_TCL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		runtest.1
INFO=		${PORTNAME}

.include <bsd.port.mk>
