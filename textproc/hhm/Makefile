# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	hhm
PORTVERSION=	0.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML Help Maker

LIB_DEPENDS=	liblzxcomp.so:${PORTSDIR}/archivers/liblzxcomp

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/hhm

post-patch:
	${REINPLACE_CMD} -e 's!^typedef unsigned.*$$!!' ${WRKSRC}/hhm.c

.include <bsd.port.mk>
