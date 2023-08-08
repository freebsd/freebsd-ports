PORTNAME=	pinfo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.13
PORTREVISION=	1
CATEGORIES=	misc

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# PR 27 and PR 34
PATCHFILES+=	fc67ceacd81f0c74fcab85447c23a532ae482827.patch:-p1 \
		ab604fdb67296dad27f3a25f3c9aabdd2fb8c3fa.patch:-p1 \
		db0f2b808103d44fa36ea6c96321b87da9ac1add.patch:-p1

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Ncurses based, lynx style info documentation browser
WWW=		https://github.com/baszoetekouw/pinfo

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gettext-tools libtool localbase makeinfo ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	baszoetekouw

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
