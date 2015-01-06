# Created by: bsam
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	textproc linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux/i386 binary port of Expat XML-parsing library (Linux Fedora 10)

CONFLICTS=	linux-expat-[0-9]* linux-f8-expat-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	5
BRANDELF_FILES=	usr/bin/xmlwf
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libexpat.so.1 lib/libexpat.so.1.5.2 \
		usr/bin/xmlwf usr/share/man/man1/xmlwf.1.gz
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}2/pkg-descr

.include <bsd.port.mk>
