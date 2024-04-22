PORTNAME=	most
DISTVERSION=	5.2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.jedsoft.org/releases/most/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pager (like less) which has support for windows and binary files
WWW=		https://www.jedsoft.org/most/

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:devel/libslang2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-mmap

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/most \
		share/man/man1/most.1.gz
PORTDOCS=	README changes.txt lesskeys.rc most-fun.txt most.rc most.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
