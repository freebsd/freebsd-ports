# New ports collection makefile for:	mcrypt
# Date created:		Mon Jun 28 18:02:04 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libmcrypt
PORTVERSION=	2.2.4
CATEGORIES=	security
MASTER_SITES=	ftp://argeas.cs-net.gr/pub/unix/mcrypt/old/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/distfiles/

MAINTAINER=	nsayer@freebsd.org

INSTALLS_SHLIBS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-posix-threads

MAN3=		mcrypt.3

RESTRICTED=	"yes - cryptography"

.include <bsd.port.mk>
