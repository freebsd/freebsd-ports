PORTNAME=	create-cert
PORTVERSION=	2.11
CATEGORIES=	security
MASTER_SITES=	https://ee.lbl.gov/downloads/create-cert/ \
		LOCAL/leres/create-cert

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Create openssl client key and certificates

LICENSE=	BSD3CLAUSE

PLIST_FILES=	sbin/create-cert \
		share/man/man8/create-cert.8.gz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
