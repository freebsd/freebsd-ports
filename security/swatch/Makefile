# New ports collection makefile for:		swatch
# Date created:					May 2 97
# Whom:						jfitz
#
# $FreeBSD$
#

PORTNAME=	swatch
PORTVERSION= 	2.2
CATEGORIES=	security sysutils
MASTER_SITES=	ftp://ftp.stanford.edu/general/security-tools/swatch/ \
		ftp://ftp.cert.dfn.de/pub/tools/audit/swatch/

MAINTAINER=	jfitz@FreeBSD.org

NO_BUILD=	YES

MAN5=		swatch.conf.5
MAN8=		swatch.8

do-install:
		@cd ${WRKSRC}; sh ${WRKSRC}/install.sh

.include <bsd.port.mk>
