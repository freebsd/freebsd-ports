# New ports collection makefile for:	aclgen
# Date created:				17 September 1999
# Whom:					igor@zynaps.ru
#
# $FreeBSD$
#

PORTNAME=	aclgen
PORTVERSION=	2.02
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sztaki.hu/pub/private/kissg/aclgen/
DISTNAME=	aclgen-202

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Optimize Cisco routers ip access lists

NO_WRKSUBDIR=	YES

MAN1=		aclgen.1

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aclgen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aclgen.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
