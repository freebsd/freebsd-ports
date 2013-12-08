# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	freecolor
PORTVERSION=	0.8.8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rkeene.org/files/oss/freecolor/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Displays free memory as a bargraph

LIB_DEPENDS=	statgrab.8:${PORTSDIR}/devel/libstatgrab

GNU_CONFIGURE=	yes
MAKE_ENV+=	INSTALL="${INSTALL}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
PLIST_FILES=	bin/freecolor
USES=		pkgconfig

.if !defined(WITHOUT_SETGID)
BINGRP?=	kmem
BINMODE?=	2555
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not function correctly on !i386
.endif

.include <bsd.port.post.mk>
