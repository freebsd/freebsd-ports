# New ports collection makefile for:   		secure_delete
# Date created:        				24 Jul 2004
# Whom:                				Vaida Bogdan <vaida.bogdan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	secure_delete
PORTVERSION=	3.1
CATEGORIES=	security
MASTER_SITES=	http://packetstormsecurity.org/groups/thc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure data deletion toolkit

CONFLICTS=	srm-[0-9]*

MANCOMPRESSED=	no
MAN1=		srm.1 sfill.1 sswap.1 smem.1

SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
