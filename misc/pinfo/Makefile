# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pinfo
PORTVERSION=	0.6.10
CATEGORIES=	misc
MASTER_SITES=	GENTOO/distfiles \
		http://alioth.debian.org/frs/download.php/file/3351/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses based, lynx style info documentation browser

LICENSE=	GPLv2

OPTIONS_DEFINE=	READLINE NLS
OPTIONS_DEFAULT=READLINE

USE_BZIP2=	yes
USES=		ncurses
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--force
ACLOCAL_ARGS=	-I macros
AUTOMAKE_ARGS=	--add-missing --force-missing
CONFIGURE_ARGS=	--with-localedir=${PREFIX}/share/locale

CFLAGS+=	-DHAVE_LOCALE_H
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		pinfo
PLIST_FILES=	bin/pinfo etc/pinforc man/man1/pinfo.1.gz

READLINE_USES=	readline
READLINE_CONFIGURE_WITH=	readline

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.for lang in cs de eu ja nl pl pt_BR ro ru sv vi
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/pinfo.mo
.endfor
.else
USES+=		gettext:build
CONFIGURE_ARGS+=--disable-nls
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|@MKINSTALLDIRS@|$$(top_srcdir)/tools/install-sh -d|' \
		${WRKSRC}/po/Makefile.in.in

pre-configure:
	@${MKDIR} ${WRKSRC}/tools
	@${LN} -sf ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}/tools

.include <bsd.port.mk>
