# Created by: Rod Taylor
# $FreeBSD$

PORTNAME=	gxanim
PORTVERSION=	0.50
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://www.rswarren.com/code/
DISTNAME=	GXAnim-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical front end to Xanim

LICENSE=	GPLv2

RUN_DEPENDS=	xanim:${PORTSDIR}/multimedia/xanim

PLIST_FILES=	bin/gxanim
WRKSRC=	${WRKDIR}/gxanim-${PORTVERSION}

USE_BZIP2=	yes
USE_GNOME=	gtk12

NO_STAGE=	yes
.include <bsd.port.mk>
