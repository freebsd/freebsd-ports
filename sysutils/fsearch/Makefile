PORTNAME=	fsearch
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast file search utility for Unix-like systems
WWW=		https://cboxdoerfer.github.io/fsearch/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpcre2-8.so:devel/pcre2

USE_GITHUB=	yes
GH_ACCOUNT=	cboxdoerfer

USES=		meson gettext-tools gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30

post-patch:
	@${PRINTF} '\n%s\n%s;\n' int \
		'strverscmp(const char *, const char *)' \
		>> ${WRKSRC}/src/fsearch_string_utils.h

.include <bsd.port.mk>
