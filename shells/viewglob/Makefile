PORTNAME=	viewglob
PORTVERSION=	2.0.4
PORTREVISION=	10
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK add-on to bash and zsh
WWW=		https://viewglob.sourceforge.net/

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		gnome pkgconfig xorg
USE_XORG=	x11
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LDFLAGS+=	-lm

.include <bsd.port.mk>
