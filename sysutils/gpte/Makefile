# Created by: Valentin Nechayev <netch@segfault.kiev.ua>
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

NO_STAGE=	yes
post-extract:
	cd $(WRKSRC) && ${CP} Makefile.bsd Makefile

.include <bsd.port.mk>
