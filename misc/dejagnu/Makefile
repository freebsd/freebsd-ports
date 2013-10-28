# Created by: markm
# $FreeBSD$

PORTNAME=	dejagnu
PORTVERSION=	1.5.1
CATEGORIES=	misc tcl tk
MASTER_SITES=	GNU

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Automated program/system tester

LICENSE=	GPLv3

BUILD_DEPENDS=	expect:${PORTSDIR}/lang/expect
RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect

USES+=		gmake tcl
GNU_CONFIGURE=	yes

INFO=		${PORTNAME}

.include <bsd.port.mk>
