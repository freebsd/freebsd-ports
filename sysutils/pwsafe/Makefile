PORTNAME=	pwsafe
DISTVERSION=	0.2.2beta-196
DISTVERSIONSUFFIX=	-g4bf61c5
CATEGORIES=	sysutils

MAINTAINER=	m.ne@gmx.net
COMMENT=	Command-line encrypted password database manager

LICENSE=	GPLv2+

FLAVORS=		x11 nox11
FLAVOR?=		${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

USES=		autoreconf gmake ncurses readline ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_curses_h=yes
USE_GITHUB=	yes
GH_ACCOUNT=	nsd20463
GH_TAGNAME=	4bf61c5

PLIST_FILES=	bin/pwsafe \
		man/man1/pwsafe.1.gz

OPTIONS_DEFINE=	SETUID
SETUID_DESC=	Install setuid pwsafe binary

.if ${FLAVOR} == "x11"
USES+=			xorg
USE_XORG=		ice sm x11 xmu
.elif ${FLAVOR} == "nox11"
CONFIGURE_ARGS+=	--without-x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwsafe ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pwsafe.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-SETUID-on:
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/pwsafe

.include <bsd.port.mk>
