# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups-lpr
PORTVERSION=	${CUPS_PORTVER}
PORTREVISION=	0
PORTEPOCH=	${CUPS_PORTEPOCH}
CATEGORIES=	print
MASTER_SITES=	${CUPS_MASTER_SITES}

MAINTAINER=	alane@FreeBSD.org

post-install:
	${FIND} ${PREFIX}/man/cat* -type l -name '*.0' -delete
	${FIND} ${PREFIX}/man/fr/cat* -type l -name '*.0' -delete

.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>

#EOF
