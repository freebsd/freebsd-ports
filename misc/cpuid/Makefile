# ex:ts=8
# New ports collection makefile for:	cpuid
# Date created:			May 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cpuid
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.ka9q.net/code/cpuid/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CPU identification utility

PLIST_FILES=	bin/cpuid
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s,gcc,${CC},g ; s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${PREFIX}/bin

.include <bsd.port.mk>
