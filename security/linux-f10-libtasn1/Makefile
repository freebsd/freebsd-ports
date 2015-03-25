# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	libtasn1
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ASN.1 structure parser library

USES+=	cpe
CPE_VENDOR=	gnu

USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	1.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libtasn1.so.3 usr/lib/libtasn1.so.3.0.16
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING COPYING.LIB ChangeLog NEWS README THANKS TODO libtasn1.pdf
DESCR=		${.CURDIR}/../libtasn1/pkg-descr

.include <bsd.port.mk>
