# New ports collection makefile for:	viewglob
# Date created:			06 Oct 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	viewglob
PORTVERSION=	2.0.4
PORTREVISION=	4
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ add-on to bash and zsh

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_XORG=	x11
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

MAN1=		vgd.1 vgseer.1 viewglob.1

.include <bsd.port.mk>
