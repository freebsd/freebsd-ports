# New ports collection makefile for:	pine4-ssl
# Version required:     1.0
# Date created:		22 June 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1999/06/23 07:30:53 nsayer Exp $
#
# I spent a <strong>very frustrating</strong> half hour with portlint
# on this one and could never get it to fewer than 8 frigging warnings.
# Good luck to you. :-P

PKGNAME=        pine-4.10+ssl-1.0

DISTNAME=	pine4+ssl-1.0

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pine4.10${EXTRACT_SUFX}

CATEGORIES=	mail news

MAINTAINER=	nsayer@freebsd.org

BUILD_DEPENDS+=	${PREFIX}/lib/libssl.a:${PORTSDIR}/security/openssl \
		${PREFIX}/lib/libcrypto.a:${PORTSDIR}/security/openssl \
		${PREFIX}/lib/libRSAglue.a:${PORTSDIR}/security/openssl \
		${PREFIX}/lib/librsaref.a:${PORTSDIR}/security/rsaref

EXTRACT_ONLY=	pine4.10${EXTRACT_SUFX}

RESTRICTED=	"Contains cryptography - no export from US"

WRKSRC=		${WRKDIR}/pine4.10

MASTERDIR=	${.CURDIR}/../pine4

FILESDIR=	${.CURDIR}/files

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='Please fill out the form at http://www.kfu.com/~nsayer/encryption/pine.html and place the sources at ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} then run make again'
.endif

post-extract:
	( cd ${WRKSRC} ; tar xfz ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} )

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf EXTRAAUTHENTICATORS=ssl)

.include "${MASTERDIR}/Makefile"
