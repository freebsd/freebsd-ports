# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	Wingz
PORTVERSION=	142
PORTREVISION=	2
CATEGORIES=	math linux
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial/spreadsheet
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Commercial Spreadsheet

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs

NO_WRKSUBDIR=	yes

# XXX: this is missing "${BRANDELF} -t Linux <executables>"

NO_STAGE=	yes
post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
