# New ports collection makefile for:	smbfs
# Date created:				2th Dec 2000
# Whom:					Jaedoc Lee <tokky@fdns.org>
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

MAINTAINER=	fjoe@freebsd.org

NO_WRKSUBDIR=	yes
NO_PACKAGE=	"Depends on kernel"
ONLY_FOR_ARCHS=	i386

post-extract:
	@${GZCAT} ${DISTDIR}/${DISTFILES} > ${WRKDIR}/sbniconfig.c
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
