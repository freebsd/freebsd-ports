# New ports collection makefile for:	OpenSSH
# Version required:	19991107
# Date created:		7 October 1999
# Whom:			green
#
# $FreeBSD$
#

DISTNAME=	OpenSSH-1.2
CATEGORIES=	security
MASTER_SITES=	# see ${SCRIPTDIR}/fetchit

MAINTAINER=	green@FreeBSD.org

LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl

RESTRICTED=	"Links with cryptographic code."

# Here, MANDIR is concetenated to DESTDIR which all forms the man install dir...
MAKE_ENV=	DESTDIR=${PREFIX} MANDIR=/man/man
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
MAKE_ENV+=	CRYPTOLIBS="-L${PREFIX}/lib -lcrypto -lRSAglue -lrsaref"
.else
MAKE_ENV+=	CRYPTOLIBS="-L${PREFIX}/lib -lcrypto"
.endif
.if !exists(/usr/include/tcpd.h)
MAKE_ENV+=	TCP_WRAPPERS=NO
.endif
NO_CHECKSUM=	YES
WRKSRC=		${WRKDIR}/ssh

do-fetch:
.if !exists(${WRKDIR}/.fetch_done)
	@${SETENV} WRKDIR=${WRKDIR} ${SCRIPTDIR}/fetchit)
.endif
	@${TOUCH} ${WRKDIR}/.fetch_done

do-extract:
	@${CP} ${FILESDIR}/strlcpy.c ${WRKSRC}/lib/

pre-install:
	@cd ${WRKSRC} && ${MAKE} DESTDIR=${PREFIX} distribution

.include <bsd.port.mk>
