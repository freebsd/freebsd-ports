# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	ised
PORTVERSION=	2.4.1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Tool for generating number sequences and arithmetic evaluation

LICENSE=	GPLv3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GCC=	4.6+

MAN1=		${PORTNAME}.1

PLIST_FILES=		bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
