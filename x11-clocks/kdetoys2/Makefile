# New ports collection makefile for:	kdetoys-i18n
# Date created:		18 may 1999
# Whom:			imura@cs.titech.ac.jp
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../audio/kdemultimedia11-i18n
PORTNAME=	kdetoys
CATEGORIES=	x11-clocks kde

MAINTAINER=	imura@FreeBSD.org

BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

.include "${MASTERDIR}/Makefile"

CONFIGURE_ENV+=	DO_NOT_COMPILE=mouse
