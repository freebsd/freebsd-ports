# New ports collection makefile for:	ipad_charge
# Date created:		13 January 2012
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipad_charge
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rainbow-software.org/linux_files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	An iPad/iPad2 USB charging utility

LDFLAGS+=	-lusb
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/ipad_charge

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
BROKEN=		does not compile
.endif

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c \
		-o ${WRKSRC}/${PORTNAME}
	
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
