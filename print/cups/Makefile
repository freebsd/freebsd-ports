# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	${CUPS_PORTVER}
PORTREVISION=	1
PORTEPOCH=	${CUPS_PORTEPOCH}
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	alane@FreeBSD.org

LIB_DEPENDS+=	cups.2:${.CURDIR}/../../print/cups-base
RUN_DEPENDS+=	espgs:${.CURDIR}/../../print/cups-pstoraster \
		${LOCALBASE}/sbin/cupsaddsmb:${.CURDIR}/../../print/cups-lpr

.if make(package)
DEPENDS_TARGET="package"
.endif # make(package)

USE_PERL5=	yes
NO_BUILD=	true

do-patch:
	${DO_NADA}

do-install:
	${DO_NADA}

.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>

#EOF
