# New ports collection makefile for:	nvramtool
# Date created:				13 Mar 2011
# Whom:					Andrey Zonov <andrey@zonov.org>
#
# $FreeBSD$
#

PORTNAME=	nvramtool
PORTVERSION=	r6440
CATEGORIES=	sysutils
MASTER_SITES=	http://www.zonov.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	zont@FreeBSD.org
COMMENT=	A utility for reading, writing the contents of CMOS memory

USE_BZIP2=	yes
USE_GMAKE=	yes

ONLY_FOR_ARCHS=	amd64 i386

PLIST_FILES=	bin/${PORTNAME}

MAN8=		${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cli/${MAN8} ${MANPREFIX}/man/man8

.include <bsd.port.mk>
