# Created by: jack
# $FreeBSD$

PORTNAME=	asfsm
PORTVERSION=	1.0.p15
PORTREVISION=	2
CATEGORIES=	sysutils afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asfsm/
DISTNAME=	asfsm-1.0pre15

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File-system monitor for the AfterStep window manager

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-07

USE_XORG=	xpm x11 sm ice xext xaw xt
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_MAN} ${WRKSRC}/asfsm.man ${STAGEDIR}${PREFIX}/man/man1/asfsm.1
	${INSTALL_PROGRAM} ${WRKSRC}/asfsm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
