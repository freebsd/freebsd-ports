# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	keynote
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www1.cs.columbia.edu/~angelos/Code/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Trust-Management System

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# gmake required to support parallel (-jX) builds
USES=		gmake ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SSLEAY="${OPENSSLBASE}/bin" OPENSSLLIB="${OPENSSLLIB}" \
		OPENSSLINC="${OPENSSLINC}"

PLIST_FILES=	bin/keynote include/keynote.h lib/libkeynote.a \
		man/man1/keynote.1.gz man/man3/keynote.3.gz \
		man/man5/keynote.5.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct evp_pkey_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct evp_pkey_st'
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynote ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/keynote.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libkeynote.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/keynote.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/keynote.3 ${STAGEDIR}${MANPREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/man/keynote.4 \
		${STAGEDIR}${MANPREFIX}/man/man5/keynote.5

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HOWTO.add.crypto ${WRKSRC}/TODO \
		${WRKSRC}/doc/rfc*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
