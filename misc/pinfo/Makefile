# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pinfo
PORTVERSION=	0.6.10
CATEGORIES=	misc
MASTER_SITES=   http://spout.ussg.indiana.edu/linux/gentoo/distfiles/ \
		http://ftp.yellowdoglinux.com/.2/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses based, lynx style info documentation browser

LICENSE=	GPLv2

OPTIONS_DEFINE=	READLINE
OPTIONS_DEFAULT=READLINE

USE_BZIP2=	yes
USES=		ncurses gettext
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--force
ACLOCAL_ARGS=	-I macros
AUTOMAKE_ARGS=	--add-missing --force-missing
CONFIGURE_ARGS=	--with-localedir=${PREFIX}/share/locale

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		pinfo.1
INFO=		pinfo

.include <bsd.port.options.mk>

PLIST_FILES=	bin/pinfo etc/pinforc
.for lang in cs de eu ja nl pl pt_BR ro ru sv vi
PLIST_FILES+=	%%NLS%%share/locale/${lang}/LC_MESSAGES/pinfo.mo
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MREADLINE}
USES+=		readline
.else
CONFIGURE_ARGS+=--without-readline
.endif

pre-configure:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/autopoint)

.include <bsd.port.mk>
