# Created by: donnex
# $FreeBSD$

PORTNAME=	pwsafe
DISTVERSION=	0.2.0-155
DISTVERSIONSUFFIX=	-g1dbcfd0
CATEGORIES=	sysutils

MAINTAINER=	m.ne@gmx.net
COMMENT=	Cmdline program that manages encrypted password databases

LICENSE=	GPLv2

USES=		autoreconf gmake ncurses readline ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nsd20463
GH_PROJECT=	pwsafe
GH_TAGNAME=	1dbcfd0

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_curses_h=yes

PLIST_FILES=	bin/pwsafe \
		man/man1/pwsafe.1.gz

OPTIONS_DEFINE=	SETUID X11

SETUID_DESC=	Install setuid pwsafe binary

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
