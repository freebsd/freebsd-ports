# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	keynote
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www1.cs.columbia.edu/~angelos/Code/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Trust-Management System

LICENSE=	MIT

USES=		gmake		# required to support parallel (-jX) builds
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SSLEAY="${OPENSSLBASE}/bin" OPENSSLLIB="${OPENSSLLIB}" \
		OPENSSLINC="${OPENSSLINC}"

MAN1=		keynote.1
MAN3=		keynote.3
MAN5=		keynote.5
PLIST_FILES=	bin/keynote include/keynote.h lib/libkeynote.a
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynote ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keynote.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/libkeynote.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/keynote.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/keynote.3 ${MANPREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/man/keynote.4 ${MANPREFIX}/man/man5/keynote.5
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HOWTO.add.crypto ${WRKSRC}/TODO \
		${WRKSRC}/doc/rfc*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
