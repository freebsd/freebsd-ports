# New ports collection makefile for:	file
# Date created:		2001-11-10
# Whom:			Jason Harris <jharris@widomaker.com>
#
# $FreeBSD$
#

PORTNAME=	file
PORTVERSION=	3.37
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.gw.com/mirrors/pub/unix/file/ \
		ftp://ftp.netsw.org/system/tools/fileutils/find/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsect-man5
MAN1=		file.1
MAN5=		magic.5

.include <bsd.port.mk>
