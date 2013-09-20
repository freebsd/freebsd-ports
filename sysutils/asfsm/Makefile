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

USE_XORG=	xpm x11 sm ice xext xaw xt
GNU_CONFIGURE=	yes

MAN1=		asfsm.1
PLIST_FILES=	bin/asfsm

NO_STAGE=	yes
do-install:
	${INSTALL_MAN} ${WRKSRC}/asfsm.man ${PREFIX}/man/man1/asfsm.1
	${INSTALL_PROGRAM} ${WRKSRC}/asfsm ${PREFIX}/bin

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you would like to be able to mount and umount file systems"
	@${ECHO_MSG} "using asfsm, as root, type \`chmod 4555 ${PREFIX}/bin/asfsm\`"
	@${ECHO_MSG} "NOTE: This opens a SECURITY HOLE as ALL users will have this ability."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
