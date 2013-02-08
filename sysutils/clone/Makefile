# $FreeBSD$

PORTNAME=	clone
PORTVERSION=	r18
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	cyclaero@gmail.com
COMMENT=	File tree cloning tool

LICENSE=	BSD

PLIST_FILES=	bin/clone

MAN1=	clone.1

post-patch-script:
	@${REINPLACE_CMD} 's|^CC      = gcc|CC      ?= gcc|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
