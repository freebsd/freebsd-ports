# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	jmba
PORTVERSION=	0.5.5
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Junk Mail Buffering Agent

GNU_CONFIGURE=	yes
USES=	gmake tar:bzip2

BROKEN_aarch64=	Fails to build: gmake: msgfmt: Command not found

PLIST_FILES=	bin/jmba \
		man/man1/jmba.1.gz

.include <bsd.port.mk>
