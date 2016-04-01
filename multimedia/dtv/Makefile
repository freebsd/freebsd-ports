# Created by: dillon
# $FreeBSD$

PORTNAME=	dtv
PORTVERSION=	0.50
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client/server based TV capture/display program

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	wish8.4:x11-toolkits/tk84

MAKE_ENV=	X11BASE=${LOCALBASE}
USES=		uidfix
USE_XORG=	xau x11 xext xxf86dga
NOT_FOR_ARCHS=	sparc64

PLIST_FILES=	bin/dtv \
		etc/dtv-xevent.tk

post-patch:
	@${REINPLACE_CMD} -e 's|^\(LDADD +=.*\)|\1 -lxcb -lXau -lXdmcp|' \
		-e 's|$$(PREFIX)/etc|${STAGEDIR}${PREFIX}/etc|' \
		-e 's/NOMAN/NO_MAN/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
