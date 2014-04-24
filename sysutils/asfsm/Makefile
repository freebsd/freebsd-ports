# Created by: jack
# $FreeBSD$

PORTNAME=	asfsm
DISTVERSION=	1.0pre15
PORTREVISION=	3
CATEGORIES=	sysutils afterstep
MASTER_SITES=	AFTERSTEP/apps/asfsm/ \
		http://tigr.net/afterstep/download/asfsm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File-system monitor for the AfterStep window manager

LICENSE=	GPLv2

USE_XORG=	ice sm x11 xaw xext xpm xt
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	bin/asfsm man/man1/asfsm.1.gz

post-build:
	@${LN} -sf asfsm.man ${WRKSRC}/asfsm.1

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} asfsm \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} asfsm.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
