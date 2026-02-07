PORTNAME=	pstacku
PORTVERSION=	0.10.0
CATEGORIES=	sysutils devel

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Retrieve process stack traces
WWW=		https://github.com/kostikbel/pstacku

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libunwind.so:devel/libunwind

USES=		autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	kostikbel
GH_TAGNAME=	f2b80d40993f689539ae46ea0b985d7332aa317f

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libunwind=${LOCALBASE}
LLD_UNSAFE=	yes
ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	pstack

PLIST_FILES=	bin/pstack share/man/man1/pstack.1.gz

.include <bsd.port.mk>
