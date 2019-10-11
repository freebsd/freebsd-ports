# $FreeBSD$

PORTNAME=	sslsplit
PORTVERSION=	0.5.5
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/rel/sslsplit/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Transparent and scalable SSL/TLS interception

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent \
		libnet.so:net/libnet

USES=		gmake pkgconfig tar:bzip2 uidfix ssl
MAKEFILE=	GNUmakefile
MAKE_ENV=	DESTDIR=${STAGEDIR} MANDIR=${PREFIX}/man INSTALLUID=${UID} INSTALLGID=${GID}
PLIST_FILES=	bin/sslsplit man/man1/sslsplit.1.gz man/man5/sslsplit.conf.5.gz \
		"@sample %%ETCDIR%%/sslsplit.conf.sample"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sslsplit

.include <bsd.port.mk>
