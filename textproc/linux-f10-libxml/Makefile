# New ports collection makefile for: linux-libxml
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libxml
.if (${MACHINE_ARCH} == "i386")
PORTVERSION=	1.4.0
.elif (${MACHINE_ARCH} == "alpha")
PORTVERSION=	1.7.3
.endif
CATEGORIES=	textproc linux

MAINTAINER=	taoka@FreeBSD.org

RPM_SET=	libxml-${PORTVERSION}-1.${MACHINE_ARCH}.rpm

.include "../../x11-toolkits/linux-gtk/Makefile"
