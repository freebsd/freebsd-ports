# New ports collection makefile for:    wingz
# Date created:         Wed Nov 27 09:15:10 CST 1996
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	Wingz
PORTVERSION=	142
PORTREVISION=	2
CATEGORIES=	math linux
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial/spreadsheet
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Commercial Spreadsheet

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes

NO_WRKSUBDIR=	yes

# XXX: this is missing "${BRANDELF} -t Linux <executables>"

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
