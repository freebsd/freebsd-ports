# New ports collection makefile for:	keynote
# Version required:                     2-beta4
# Date created:                         02 September 1999
# Whom:                                 se
#
# $FreeBSD$
#

DISTNAME=	keynote-2-beta4
PKGNAME=	keynote-2b4
CATEGORIES=	security
MASTER_SITES=	http://www.cis.upenn.edu/~angelos/Code/

MAINTAINER=	se@FreeBSD.org

BUILD_DEPENDS=	openssl:${PORTSDIR}/security/openssl
LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl \
		ssl.1:${PORTSDIR}/security/openssl

WRKSRC=		${WRKDIR}/KeyNote-2-beta4

MAN1=		keynote.1
MAN3=		keynote.3
MAN4=		keynote.4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynote ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.3 ${PREFIX}/man/man3/
	${INSTALL_DATA} ${WRKSRC}/man/keynote.4 ${PREFIX}/man/man4/
	${MKDIR} ${PREFIX}/share/doc/keynote/
	${INSTALL_DATA} ${WRKSRC}/doc/keynote-spec ${PREFIX}/share/doc/keynote/
	${INSTALL_DATA} ${WRKSRC}/doc/keynote-spec.nroff ${PREFIX}/share/doc/keynote/

.include <bsd.port.mk>
