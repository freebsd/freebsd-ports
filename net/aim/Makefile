# New ports collection makefile for:	aim
# Date created:		Sat Jan 13 12:40:20 GMT 2001
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	aim
PORTVERSION=	1.5.234
CATEGORIES=	net linux
MASTER_SITES=	ftp://ftp.newaol.com/aimgen/73010/
DISTNAME=	aim-${PORTVERSION}-1
EXTRACT_SUFX=	.i386.tgz

MAINTAINER=	p9711422@mmu.edu.my

RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		/compat/linux/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

ONLY_FOR_ARCHS=	i386
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_XLIB=	yes

# This port will only work when PREFIX is /usr/local because the aim
# program is hard coded to look for important files in /usr/local/lib/aim
PREFIX=		/usr/local

do-install:
	${CP} ${WRKSRC}/usr/local/bin/aim ${PREFIX}/bin
	${CP} ${WRKSRC}/usr/local/lib/lib* ${PREFIX}/lib
	${MKDIR} ${PREFIX}/lib/aim
	${CP} -R ${WRKSRC}/usr/local/lib/aim/* ${PREFIX}/lib/aim
	${RM} -rf ${PREFIX}/lib/aim/source

.include <bsd.port.mk>
