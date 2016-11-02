# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nero
PORTVERSION=	4.0.0.0
PORTREVISION=	2
CATEGORIES=	sysutils emulators
MASTER_SITES=	http://ftp20.us.nero.com/software/NeroLINUX/
DISTNAME=	${PORTNAME}linux-${PORTVERSION}-x86
EXTRACT_SUFX=	.rpm
DIST_SUBDIR=	rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	CD/DVD disk burner

RESTRICTED=	Must be downloaded from their website and a serial number must be bought

USES=		linux
USE_LDCONFIG=	yes
USE_LINUX=	gtk2
USE_LINUX_RPM=	nolib
SRC_DISTFILES=
PLIST=		${PKGDIR}/pkg-plist

.include <bsd.port.mk>
