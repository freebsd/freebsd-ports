PORTNAME=	fdupes
DISTVERSION=	2.3.2
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/adrianlopezroche/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Program for identifying or deleting duplicate files
WWW=		https://github.com/adrianlopezroche/fdupes/

LICENSE=	MIT

USES=		localbase pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/fdupes \
		share/man/man1/fdupes.1.gz

OPTIONS_DEFINE=		NCURSES SQLITE
OPTIONS_DEFAULT=	NCURSES

NCURSES_LIB_DEPENDS=	libpcre2-32.so:devel/pcre2
NCURSES_USES=		ncurses:base
NCURSES_CONFIGURE_OFF=	--without-ncurses
NCURSES_PLIST_FILES=	share/man/man7/fdupes-help.7.gz
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_OFF=	--without-sqlite

.include <bsd.port.mk>
