PORTNAME=	pinfo
DISTVERSION=	0.6.13
CATEGORIES=	misc
MASTER_SITES=

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Ncurses based, lynx style info documentation browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gettext-tools libtool localbase makeinfo ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	baszoetekouw
GH_TAGNAME=	v${DISTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-curses=${NCURSESBASE}

INFO=		pinfo
PLIST_FILES=	bin/pinfo \
		etc/pinforc \
		man/man1/pinfo.1.gz

OPTIONS_DEFINE=			NLS READLINE
OPTIONS_DEFAULT=		READLINE
READLINE_USES=			readline
READLINE_CONFIGURE_WITH=	readline

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext-runtime
.for lang in cs de eu ja nl pl pt_BR ro ru sv vi
PLIST_FILES+=		share/locale/${lang}/LC_MESSAGES/pinfo.mo
.endfor
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.include <bsd.port.mk>
