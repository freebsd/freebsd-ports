# New ports collection makefile for:	aclgen
# Version required:			2.02
# Date created:				17 September 1999
# Whom:					igor@zynaps.ru
#
# $FreeBSD$
#

DISTNAME=	aclgen-202
PKGNAME=	aclgen-2.02
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sztaki.hu/pub/private/kissg/aclgen/

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	YES

MAN1=		aclgen.1

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aclgen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aclgen.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
