# New ports collection makefile for:	devcpu-data
# Date created:		2007-07-19
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.5
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
PKGNAMEPREFIX=	devcpu-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intel and AMD CPUs microcode updates

USE_BZIP2=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 701102
DATADIR=	${PREFIX}/share/cpucontrol
.else
DATADIR=	${PREFIX}/share/devcpu
.endif

USE_RC_SUBR=	microcode_update

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${DATADIR}/
	@${TOUCH} ${DATADIR}/.do_not_delete

.include <bsd.port.post.mk>
