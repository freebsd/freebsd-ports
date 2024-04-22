PORTNAME=	dejagnu
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	misc tcl
MASTER_SITES=	GNU

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Automated program/system tester
WWW=		https://www.gnu.org/software/dejagnu/

LICENSE=	GPLv3

LIB_DEPENDS=	libexpect.so:lang/expect

USES+=		gmake tcl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INFO=		${PORTNAME}

TEST_TARGET=	check

.include <bsd.port.mk>
