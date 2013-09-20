# Created by: stas
# $FreeBSD$

PORTNAME=	vimperator
PORTVERSION=	3.5
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Vim look and feel for Firefox

LICENSE=MIT
LICENSE_FILE=${WRKSRC}/License.txt

XPI_ID=		vimperator@mozdev.org
XPI_NUM=	4891

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
