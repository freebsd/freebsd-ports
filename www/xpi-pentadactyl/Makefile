# Created by: clutton mbsd@isgroup.com.ua
# $FreeBSD$

PORTNAME=	pentadactyl
PORTVERSION=	1.0r1
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www
DISTNAME=	pentadactyl-${PORTVERSION:S/r/rc/}${DISTVERSIONSUFFIX}

MAINTAINER=	mbsd@isgroup.com.ua
COMMENT=	Firefox for Vim and Links addicts

IGNORE=		does not work with firefox 15+

XPI_NUM=	235854
XPI_ID=		pentadactyl@dactyl.googlecode.com

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
