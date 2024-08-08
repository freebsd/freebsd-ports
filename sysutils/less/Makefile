PORTNAME=	less
DISTVERSION=	661
CATEGORIES=	sysutils
MASTER_SITES=	http://www.greenwoodsoftware.com/less/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Better pager utility
WWW=		https://www.greenwoodsoftware.com/less/

LICENSE=	GPLv3+ MIT
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		cpe gmake ncurses

CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/less \
		bin/lessecho \
		bin/lesskey \
		share/man/man1/less.1.gz \
		share/man/man1/lessecho.1.gz \
		share/man/man1/lesskey.1.gz

OPTIONS_DEFINE=		COLORS PCRE
OPTIONS_DEFAULT=	COLORS PCRE

COLORS_DESC=		Enable colors support via escape sequence
COLORS_CPPFLAGS=	-DCOLOR_LESS

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_USES=		localbase
PCRE_CONFIGURE_ON=	--with-regex=pcre
PCRE_CONFIGURE_OFF=	--with-regex=posix
PCRE_LDFLAGS=		-L${LOCALBASE}/lib -lpcre

.include <bsd.port.mk>
