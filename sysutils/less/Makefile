PORTNAME=	less
PORTVERSION=	551
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.greenwoodsoftware.com/less/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Better pager utility
WWW=		https://www.greenwoodsoftware.com/less/

LICENSE=	GPLv3+ MIT
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		cpe ncurses

CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/less \
		bin/lessecho \
		bin/lesskey \
		share/man/man1/less.1.gz \
		share/man/man1/lessecho.1.gz \
		share/man/man1/lesskey.1.gz

OPTIONS_DEFINE=		COLORS PCRE
OPTIONS_DEFAULT=	COLORS PCRE

PCRE_USES=		localbase
PCRE_CONFIGURE_ON=	--with-regex=pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_LDFLAGS=		-L${LOCALBASE}/lib -lpcre
PCRE_CONFIGURE_OFF=	--with-regex=posix

COLORS_DESC=		Enable colors support via escape sequence
COLORS_CPPFLAGS=	-DCOLOR_LESS

.include <bsd.port.mk>
