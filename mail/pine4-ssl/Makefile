# New ports collection makefile for:	pine4-ssl
# Date created:		29 Jul 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#
# I spent a <strong>very frustrating</strong> half hour with portlint
# on this one and could never get it to fewer than 8 frigging warnings.
# A bit more work got it down to 2 frigging warnings.
# The warnings are getting harder to fix.
# Good luck to you. :-P

PORTNAME=	pine4-ssl
PORTVERSION= 	4.21.1.4
CATEGORIES=	mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		http://www.kfu.com/~nsayer/encryption/software/
DISTNAME=	pine4+ssl-1.4
DISTFILES=	pine4.21${EXTRACT_SUFX}

PATCH_SITES=	http://www.kfu.com/~nsayer/encryption/software/
PATCHFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nsayer@freebsd.org

EXTRACT_ONLY=	pine4.21${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/pine4.21

MASTERDIR=	${.CURDIR}/../pine4

FILESDIR=	${.CURDIR}/files

EXTRA_PATCHES=	${FILESDIR}/extrapatch-*

USE_OPENSSL=	RSA

.include <bsd.port.pre.mk>

post-extract:
	( cd ${WRKSRC} ; tar xfz ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} )

do-build:
.if defined(OPENSSL_RSAREF)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf EXTRAAUTHENTICATORS=ssl RSAREF=yes)
.else
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf EXTRAAUTHENTICATORS=ssl)
.endif

PRE_MK_INCLUDED=	yes
.include "${MASTERDIR}/Makefile"
