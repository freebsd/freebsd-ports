# ex:ts=8
# New ports collection makefile for:	cpuid
# Date created:			May 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cpuid
PORTVERSION=	3.3
CATEGORIES=	misc
MASTER_SITES=	http://people.qualcomm.com/karn/code/cpuid/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s,gcc,${CC},g ; s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${PREFIX}/bin

.include <bsd.port.mk>
