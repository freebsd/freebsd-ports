# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	fsearch
PORTVERSION=	0.1.2
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	7f602118e0de9f524e71.diff:-p1 f0ee01b40156ddb36651.diff:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast file search utility for Unix-like systems

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_check_compile_flag.m4:devel/autoconf-archive
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	cboxdoerfer

USES=		autoreconf compiler:c++11-lang gettext gmake gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool

post-patch:
	@${REINPLACE_CMD} -e 's,v=UNKNOWN,v=${DISTVERSION},' \
		${WRKSRC}/build-aux/git-version-gen
	@${PRINTF} '\n%s\n%s;\n' int \
		'strverscmp(const char *, const char *)' \
		>> ${WRKSRC}/src/fsearch_string_utils.h

.include <bsd.port.mk>
