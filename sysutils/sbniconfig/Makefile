# New ports collection makefile for:	sbniconfig
# Date created:				18 Feb 2003
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sbniconfig
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.granch.ru/pub/drivers/sbni12/FREEBSD/sbniconfig/
DISTNAME=	sbniconfig.c
EXTRACT_SUFX=	.gz
EXTRACT_ONLY=

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Configurator for Granch SBNI12-xx adapters

NO_WRKSUBDIR=	yes
NO_PACKAGE=	"Depends on kernel"
ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/sbniconfig

post-extract:
	@${GZCAT} ${DISTDIR}/${DISTFILES} > ${WRKDIR}/sbniconfig.c
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
