# Created by: freebsd@spatula.net
# $FreeBSD$

PORTNAME=	muse
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.spatula.net/muse/

MAINTAINER=	freebsd@spatula.net
COMMENT=	Shows memory usage data

BROKEN_FreeBSD_12=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'
BROKEN_FreeBSD_13=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'
BROKEN_mips=		fails to compile: muse.c: storage size of 'vmstats' isn't known
BROKEN_mips64=		fails to compile: muse.c: storage size of 'vmstats' isn't known

USES=		uidfix

PLIST_FILES=	bin/muse man/man1/muse.1.gz

.include <bsd.port.mk>
