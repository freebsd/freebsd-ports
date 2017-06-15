# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pinfo
PORTVERSION=	0.6.10
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	GENTOO \
		http://alioth.debian.org/frs/download.php/file/3351/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses based, lynx style info documentation browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		autoreconf gettext-tools libtool makeinfo ncurses tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

INFO=		pinfo
PLIST_FILES=	bin/pinfo etc/pinforc man/man1/pinfo.1.gz

OPTIONS_DEFINE=	READLINE NLS
OPTIONS_DEFAULT=READLINE
READLINE_USES=	readline
READLINE_CONFIGURE_WITH=	readline

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext-runtime
.for lang in cs de eu ja nl pl pt_BR ro ru sv vi
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/pinfo.mo
.endfor
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.mk>
