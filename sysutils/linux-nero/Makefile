# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

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

RESTRICTED=	Must be downloaded from their website and a serial number must be bought

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	gtk2
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
SRC_DISTFILES=

# normalize permissions of symbolic links to prevent a package with
# missing files
post-extract:
	${FIND} ${WRKSRC} -type l -exec ${CHMOD} -h 0755 {} \;

.include <bsd.port.mk>
