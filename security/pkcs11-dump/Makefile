# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkcs11-dump
PORTVERSION=	0.3.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Allow dumping PKCS\#11 token content

PROJECTHOST=	pkcs11-tools

USE_BZIP2=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

PLIST_FILES=	bin/pkcs11-dump

MAN1=		pkcs11-dump.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
