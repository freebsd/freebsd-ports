# Created by: markm
# $FreeBSD$

PORTNAME=	dejagnu
PORTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	misc tcl
MASTER_SITES=	GNU

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Automated program/system tester

LICENSE=	GPLv3

LIB_DEPENDS=	libexpect.so:lang/expect

USES+=		gmake tcl:85+
GNU_CONFIGURE=	yes

INFO=		${PORTNAME}

TEST_TARGET=	check

.include <bsd.port.mk>
