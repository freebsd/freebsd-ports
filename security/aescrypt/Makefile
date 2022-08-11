PORTNAME=	aescrypt
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

PATCH_SITES=	http://devel.ringlet.net/security/aescrypt/patches/ \
		http://people.FreeBSD.org/~roam/ports/patches/security/aescrypt/
PATCHFILES=	aescrypt-0.7-roam-whopper-01.patch.gz

MAINTAINER=	mauroeldritch@gmail.com
COMMENT=	Command-line AES encryption/decryption suite

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
MAKE_ENV+=	BINGRP=wheel

# Upstream dead. Don't expect a proper fix.
CFLAGS+=	-fcommon

BINS=		aescrypt aesget

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
