PORTNAME=	telegram-purple
PORTVERSION=	1.4.7
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libpurple plugin for Telegram messenger
WWW=		https://github.com/majn/telegram-purple

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	No longer works, migrate to net-im/tdlib-purple
EXPIRATION_DATE=2024-03-17

BROKEN_armv6=		fails to link: undefined reference to 'backtrace'
BROKEN_powerpc64=	fails to compile: Assertion failed: (get_int () == TLS_SCHEMA_V2), function parse_tlo_file, file generate.c, line 2832.

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libwebp.so:graphics/webp \
		libpurple.so:net-im/libpurple \
		libpng.so:graphics/png

USES=		gmake gnome pkgconfig localbase:ldflags
USE_GNOME=	glib20

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-translation

USE_GITHUB=	yes
GH_ACCOUNT=	majn
GH_PROJECT=	tgl:tgl
GH_TAGNAME?=	cd7e3d7:tgl
GH_SUBDIR=	tgl:tgl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/purple-2/telegram-purple.so
	@${RM} -rf ${STAGEDIR}/etc

.include <bsd.port.mk>
