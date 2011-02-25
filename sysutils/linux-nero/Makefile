# New ports collection makefile for:	sysutils/linux-nero
# Date created:				23 Apr 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nero
PORTVERSION=	4.0.0.0
PORTREVISION=	2
CATEGORIES=	sysutils emulators
MASTER_SITES=	http://ftp6.usw.nero.com/software/NeroLINUX/ \
		ftp://ftp6.usw.nero.com/software/NeroLINUX/
DISTNAME=	${PORTNAME}linux-${PORTVERSION}-x86
EXTRACT_SUFX=	.rpm
DIST_SUBDIR=	rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	CD/DVD disk burner

RESTRICTED=	Get a serial number at http://www.nero.com/eng/NeroLINUX.html

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	gtk2                                                        
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
SRC_DISTFILES=

.include <bsd.port.mk>
