# Created by: bsam
# $FreeBSD: head/textproc/linux-f10-libxml2/Makefile 362315 2014-07-20 12:13:43Z rene $

PORTNAME=	libxml2
PORTVERSION=	2.7.3
PORTREVISION=	2
CATEGORIES=	textproc linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library providing XML and HTML support (Linux Fedora 10)

FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=57f1a624-6197-11e1-b98c-bcaec565249c|7be92050-a450-11e2-9898-001060e06fd4|b8ae4659-a0da-11e1-a294-bcaec565249c

CONFLICTS=	linux-libxml2-[0-9]* linux-f8-libxml2-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/xmlcatalog usr/bin/xmllint \
		usr/lib/libxml2.so.2 usr/lib/libxml2.so.${PORTVERSION} \
		usr/share/man/man1/xmlcatalog.1.gz \
		usr/share/man/man1/xmllint.1.gz usr/share/man/man3/libxml.3.gz
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS ChangeLog.gz Copyright NEWS README TODO
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
