PORTNAME=	create-cert
PORTVERSION=	2.12
CATEGORIES=	security
MASTER_SITES=	https://ee.lbl.gov/downloads/create-cert/ \
		LOCAL/leres/create-cert

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Create openssl client key and certificates
WWW=		https://ee.lbl.gov/downloads/create-cert/

LICENSE=	BSD3CLAUSE

PLIST_FILES=	sbin/create-cert \
		share/man/man8/create-cert.8.gz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
