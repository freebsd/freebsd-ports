# New ports collection makefile for:	kdetoys-i18n
# Version required:	1.1.2
# Date created:		18 may 1999
# Whom:			imura@cs.titech.ac.jp
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../audio/kdemultimedia11-i18n

CATEGORIES=	x11-clocks kde

MAINTAINER=	imura@kde.gr.jp

BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

KDE_NAME=	kdetoys

.include "${MASTERDIR}/Makefile"

CONFIGURE_ENV+=	DO_NOT_COMPILE=mouse
