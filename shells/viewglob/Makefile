# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	viewglob
PORTVERSION=	2.0.4
PORTREVISION=	7
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ add-on to bash and zsh

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		pkgconfig
USE_XORG=	x11
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

MAN1=		vgd.1 vgseer.1 viewglob.1

.include <bsd.port.mk>
