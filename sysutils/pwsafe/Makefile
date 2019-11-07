# Created by: donnex
# $FreeBSD$

PORTNAME=	pwsafe
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://nsd.dyndns.org/pwsafe/releases/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Cmdline program that manages encrypted password databases

BROKEN=		unfetchable

LICENSE=	GPLv2

OPTIONS_DEFINE=	SETUID X11
SETUID_DESC=	Install setuid pwsafe binary

USES=		gmake ncurses readline ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_curses_h=yes

PLIST_FILES=	bin/pwsafe man/man1/pwsafe.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS=	--with-x
USES+=		xorg
USE_XORG=	ice sm x11 xmu
.else
CONFIGURE_ARGS=	ac_cv_have_x="have_x=no" \
		ac_cv_lib_ICE_IceConnectionNumber=no \
		ac_cv_lib_X11_XOpenDisplay=no \
		ac_cv_lib_Xmu_XmuInternAtom=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwsafe ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pwsafe.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MSETUID}
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/pwsafe
.endif

.include <bsd.port.mk>
