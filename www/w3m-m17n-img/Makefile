# New ports collection makefile for:   w3m-m17n
# Date Created:                11 January 2004
# Whom:                        MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-m17n-img

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A pager/text-based WWW browser with m17n and inline image support

MASTERDIR=	${.CURDIR}/../../www/w3m
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

M17N=		yes
INLINE_IMAGE=	yes
CONFLICTS=	ja-w3m-0.5.* ja-w3m-img-0.5.* w3m-0.5.* w3m-m17n-0.5.* w3m-img-0.5.*

.include "${MASTERDIR}/Makefile"
