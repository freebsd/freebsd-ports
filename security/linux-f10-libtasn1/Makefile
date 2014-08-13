# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD: head/security/linux-f10-libtasn1/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	libtasn1
PORTVERSION=	1.5
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ASN.1 structure parser library

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libtasn1.so.3 usr/lib/libtasn1.so.3.0.16
DOCSDIR_REL=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING COPYING.LIB ChangeLog NEWS README THANKS TODO libtasn1.pdf
DESCR=		${.CURDIR}/../libtasn1/pkg-descr

.include <bsd.port.mk>
