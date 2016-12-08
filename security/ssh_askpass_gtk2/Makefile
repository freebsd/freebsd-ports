# Created by: mig
# $FreeBSD$

PORTNAME=	ssh_askpass_gtk2
PORTVERSION=	0.4
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	http://www.cgabriel.org/download/ssh-askpass-fullscreen/
DISTNAME=	ssh-askpass-fullscreen-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Tiny GTK2 ssh askpass replacement

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gtk20
USES=		pkgconfig

PLIST_FILES=	bin/ssh-askpass-fullscreen

post-patch:
	${REINPLACE_CMD} -e "s,gcc,${CC}," \
		-e "\|${CC}|s,$$, -lX11," ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC};\
	${INSTALL_PROGRAM} ssh-askpass-fullscreen ${STAGEDIR}${PREFIX}/bin/ssh-askpass-fullscreen

.include <bsd.port.mk>
