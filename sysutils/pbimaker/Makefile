# Created by: Jesse
# $FreeBSD$

PORTNAME=	pbimaker
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/makeapbi/makeapbi/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Program to convert ports into PBI modules

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/PBIMaker

PLIST_FILES=	bin/pbimaker \
		share/pbimaker/defaulticon.png
PLIST_DIRS=	share/pbimaker

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC?=gcc|' \
		-e 's|PREFIX)/|DESTDIR)$$(&|g' \
		${WRKSRC}/Makefile
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
