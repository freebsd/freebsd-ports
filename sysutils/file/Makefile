# New ports collection makefile for:	file
# Date created:		2001-11-10
# Whom:			Jason Harris <jharris@widomaker.com>
#
# $FreeBSD$
#

PORTNAME=	file
PORTVERSION=	4.13
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.gw.com/mirrors/pub/unix/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/

MAINTAINER=	jharris@widomaker.com
COMMENT=	File - determine file type

CONFIGURE_ARGS=	--enable-fsect-man5
HAS_CONFIGURE=	yes
MAN1=		file.1
MAN3=		libmagic.3
MAN5=		magic.5

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
