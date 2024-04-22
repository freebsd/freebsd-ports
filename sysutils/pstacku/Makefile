PORTNAME=	pstacku
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://kib.kiev.ua/kib/${PORTNAME}/ \
		http://kib.kiev.ua/kib/${PORTNAME}/

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Retrieve process stack traces
WWW=		https://www.kib.kiev.ua/git/gitweb.cgi?p=pstacku.git;a=tree

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libunwind.so:devel/libunwind

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=--with-libunwind=${LOCALBASE}
LLD_UNSAFE=	yes
ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	pstack

PLIST_FILES=	bin/pstack share/man/man1/pstack.1.gz

.include <bsd.port.mk>
