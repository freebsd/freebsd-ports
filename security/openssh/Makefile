# New ports collection makefile for:	OpenSSH
# Version required:	19991107
# Date created:		7 October 1999
# Whom:			green
#
# $FreeBSD$
#

DISTNAME=	OpenSSH-1.2
CATEGORIES=	security
MASTER_SITES=	http://www.FreeBSD.org/~green/

MAINTAINER=	green@FreeBSD.org

LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl

# Here, MANDIR is concetenated to DESTDIR which all forms the man install dir...
MAKE_ENV=	DESTDIR=${PREFIX} MANDIR=/man/man
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
MAKE_ENV+=	CRYPTOLIBS="-L${PREFIX}/lib -lcrypto -lRSAglue -lrsaref"
.else
MAKE_ENV+=	CRYPTOLIBS="-L${PREFIX}/lib -lcrypto"
.endif
WRKSRC=		${WRKDIR}/ssh

pre-install:
	@cd ${WRKSRC} && ${MAKE} DESTDIR=${PREFIX} distribution

.include <bsd.port.mk>
