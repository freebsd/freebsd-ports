# Created by: Daniel Johansson <donnex@donnex.net>

PORTNAME=	pwsafe
DISTVERSION=	0.2.0-155
DISTVERSIONSUFFIX=	-g1dbcfd0
CATEGORIES=	sysutils

MAINTAINER=	m.ne@gmx.net
COMMENT=	Command-line encrypted password database manager

LICENSE=	GPLv2+

USES=		autoreconf gmake ncurses readline ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_curses_h=yes
USE_GITHUB=	yes
GH_ACCOUNT=	nsd20463
GH_TAGNAME=	1dbcfd0

PLIST_FILES=	bin/pwsafe \
		man/man1/pwsafe.1.gz

OPTIONS_DEFINE=	SETUID X11
SETUID_DESC=	Install setuid pwsafe binary

X11_USES=	xorg
X11_USE=	XORG=ice,sm,x11,xmu
X11_CONFIGURE_OFF=	--without-x

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwsafe ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pwsafe.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-SETUID-on:
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/pwsafe

.include <bsd.port.mk>
