# Ports collection makefile for:	gpte
# Date created: 12 Jan 2005
# Whom: Valentin Nechayev <netch@segfault.kiev.ua>
#
# $FreeBSD$

PORTNAME=	gpte
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://segfault.kiev.ua/pub/

MAINTAINER=	netch@segfault.kiev.ua
COMMENT=	A simple command-line GPT partition editor

MAN8=		gpte.8
MANCOMPRESSED=	yes

PLIST_FILES=	bin/gpte

post-extract:
	cd $(WRKSRC) && ${CP} Makefile.bsd Makefile

.include <bsd.port.pre.mk>

.if $(OSVERSION) < 502000
IGNORE=		Only for 5.x and later systems
.endif

.include <bsd.port.post.mk>
