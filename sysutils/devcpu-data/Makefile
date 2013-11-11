# Created by: stas
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
PKGNAMEPREFIX=	devcpu-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intel and AMD CPUs microcode updates

USE_BZIP2=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64

DATADIR=	${PREFIX}/share/cpucontrol

USE_RC_SUBR=	microcode_update

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${STAGEDIR}${DATADIR}/
	@${TOUCH} ${STAGEDIR}${DATADIR}/.do_not_delete

.include <bsd.port.mk>
