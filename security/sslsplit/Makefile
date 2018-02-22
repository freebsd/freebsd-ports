# $FreeBSD$

PORTNAME=	sslsplit
PORTVERSION=	0.5.2
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/rel/sslsplit/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Transparent and scalable SSL/TLS interception

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		gmake pkgconfig tar:bzip2 uidfix ssl
MAKEFILE=	GNUmakefile
MAKE_ENV=	DESTDIR=${STAGEDIR} MANDIR=man INSTALLUID=${UID} INSTALLGID=${GID}
PLIST_FILES=	bin/sslsplit man/man1/sslsplit.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sslsplit

.include <bsd.port.mk>
