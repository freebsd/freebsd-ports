# Ports collection makefile for:	diskmark
# Date created:				Friday, May 7, 2004
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diskmark
PORTVERSION=	0.9
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~brooks/diskmark/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A program to mark disks using empty partition table entries

# Diskmark makes little sense on arches that don't boot from MBR
# partition tables and doesn't build on 64-bit platforms with strict
# alignment (partion entries are aligned on a 2-byte boundry).
ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	sbin/diskmark

USE_BZIP2=	yes

MAN8=		diskmark.8
MANCOMPRESSED=	yes

.include <bsd.port.mk>
