# Created by: candy@fct.kgc.co.jp
# $FreeBSD$

PORTNAME=	xipmsg
PORTVERSION=	0.8088
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.bsddiary.net/xipmsg/
DISTNAME=	xipmsg-${PORTVERSION:E}

MAINTAINER=	candy@kgc.co.jp
COMMENT=	Popup style message communication tool for X11

BROKEN=		unfetchable

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

post-patch:
	@${REINPLACE_CMD} 's,^INSTUIDFLAGS=.*,INSTUIDFLAGS=${STRIP} -m ${BINMODE},' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
