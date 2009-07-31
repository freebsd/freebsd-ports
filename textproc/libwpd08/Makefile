# New ports collection makefile for:    libwpd
# Date created:         Mon May 19 09:09:10 PDT 2003
# Whom:                 reed@pugetsoundtechnology.com
#
# $FreeBSD$
#

PORTNAME=	libwpd
PORTVERSION=	0.8.14
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tools for importing and exporting WordPerfect(tm) documents

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack libgsf
USE_LDCONFIG=	yes
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

CONFIGURE_ARGS+=--without-docs

.include <bsd.port.mk>
