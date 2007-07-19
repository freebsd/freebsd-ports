# New ports collection makefile for:	devcpu-data
# Date created:		2007-07-19
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.1
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
PKGNAMEPREFIX=	devcpu-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Microcode data file to be used with sysutils/devcpu port

USE_BZIP2=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64

DATADIR=	${PREFIX}/share/devcpu

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${DATADIR}/
	@${TOUCH} ${DATADIR}/.do_not_delete

.include <bsd.port.mk>
