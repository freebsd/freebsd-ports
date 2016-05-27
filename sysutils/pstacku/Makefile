# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstacku
PORTVERSION=	0.9.2
CATEGORIES=	sysutils
MASTER_SITES=	https://kib.kiev.ua/kib/${PORTNAME}/ \
		http://kib.kiev.ua/kib/${PORTNAME}/

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	Retrieve process stack traces

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libunwind.so:devel/libunwind

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libunwind=${LOCALBASE}
ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	pstack-[0-9]*

PLIST_FILES=	bin/pstack man/man1/pstack.1.gz

.include <bsd.port.mk>
