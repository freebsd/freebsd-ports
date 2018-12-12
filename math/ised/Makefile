# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	ised
PORTVERSION=	2.7.1
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Tool for generating number sequences and arithmetic evaluation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libedit tar:bzip2
GNU_CONFIGURE=	yes
# ./base.h:620:14: error: invalid output constraint '=ir' in asm
USE_GCC=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
