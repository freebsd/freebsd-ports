# New ports collection makefile for:	pine4-ssl
# Version required:     1.4
# Date created:		29 Jul 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#
# I spent a <strong>very frustrating</strong> half hour with portlint
# on this one and could never get it to fewer than 8 frigging warnings.
# Good luck to you. :-P

PKGNAME=        pine4-ssl-4.21.1.4

DISTNAME=	pine4+ssl-1.4

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pine4.21${EXTRACT_SUFX}

CATEGORIES=	mail news

MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		http://www.kfu.com/~nsayer/encryption/noexport/

MAINTAINER=	nsayer@freebsd.org

LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl \
		ssl.1:${PORTSDIR}/security/openssl

EXTRACT_ONLY=	pine4.21${EXTRACT_SUFX}

RESTRICTED=	"Contains cryptography - no export from US"

WRKSRC=		${WRKDIR}/pine4.21

MASTERDIR=	${.CURDIR}/../pine4

FILESDIR=	${.CURDIR}/files

.include <bsd.port.pre.mk>

post-extract:
	( cd ${WRKSRC} ; tar xfz ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} )

do-build:
.if exists(${PREFIX}/lib/librsaref.a)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf EXTRAAUTHENTICATORS=ssl RSAREF=yes)
.else
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf EXTRAAUTHENTICATORS=ssl)
.endif

.include "${MASTERDIR}/Makefile"
