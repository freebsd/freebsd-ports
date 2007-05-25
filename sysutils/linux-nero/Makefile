# New ports collection makefile for:	sysutils/linux-nero
# Date created:				23 Apr 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nero
PORTVERSION=	3.0.0.0
CATEGORIES=	sysutils emulators
MASTER_SITES=	http://ftp6.usw.nero.com/software/NeroLINUX/ \
		ftp://ftp6.usw.nero.com/software/NeroLINUX/
DISTNAME=	${PORTNAME}linux-${PORTVERSION}-x86
EXTRACT_SUFX=	.rpm
DIST_SUBDIR=	rpm

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	CD/DVD disk burner (trial beta version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0:${PORTSDIR}/x11-toolkits/linux-gtk2

RESTRICTED=	Get a serial number at http://www.nero.com/eng/NeroLINUX.html

USE_LINUX_RPM=	yes
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
SRC_DISTFILES=

.include <bsd.port.mk>
