# New ports collection makefile for:   cups
# Date created:        05 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	${CUPS_PORTVER}
CATEGORIES?=	print
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	alane@FreeBSD.org

LIB_DEPENDS?=	cups.2:${.CURDIR}/../../print/cups-base
RUN_DEPENDS?=	espgs:${.CURDIR}/../../print/cups-pstoraster \
		${LOCALBASE}/sbin/cupsaddsmb:${.CURDIR}/../../print/cups-lpr

.if make(package)
DEPENDS_TARGET="package"
.endif

NO_BUILD=	true
do-install:	# empty
do-patch:	# empty

.include "${.CURDIR}/../../print/cups/Makefile.inc"
.include <bsd.port.mk>
