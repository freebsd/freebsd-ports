# New ports collection makefile for:	keynote
# Date created:                         02 September 1999
# Whom:                                 se
#
# $FreeBSD$
#

PORTNAME=	keynote
PORTVERSION=	2.2
CATEGORIES=	security
MASTER_SITES=	http://www.cis.upenn.edu/~angelos/Code/

MAINTAINER=	kris@FreeBSD.org

USE_OPENSSL=	YES
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	SSLEAY="${OPENSSLBASE}/bin" OPENSSLLIB="${OPENSSLLIB}" \
		OPENSSLINC="${OPENSSLINC}"

MAN1=		keynote.1
MAN3=		keynote.3
MAN4=		keynote.4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynote ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libkeynote.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.3 ${PREFIX}/man/man3/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.4 ${PREFIX}/man/man4/
	${MKDIR} ${PREFIX}/share/doc/keynote/
	${INSTALL_DATA} ${WRKSRC}/doc/rfc2704.txt ${PREFIX}/share/doc/keynote/

.include <bsd.port.post.mk>
