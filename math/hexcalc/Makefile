# New ports collection makefile for:	hexcalc
# Date created:		5 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	hexcalc
PORTVERSION=	1.11
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://aixpdslib.seas.ucla.edu/pub/hexcalc/RISC/3.2/src/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	..tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-radix calculator for x11

DEPRECATED=	Look like an abandonware, no more public distifles
EXPIRATION_DATE=	2011-08-01

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt
MAN1=		hexcalc.1
PLIST_FILES=	bin/hexcalc

.include <bsd.port.mk>
