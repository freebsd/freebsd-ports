# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	libtasn1
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	ASN.1 structure parser library

USES+=	cpe
CPE_VENDOR=	gnu

USE_LINUX=	c6
USE_LINUX_RPM=	yes

RPMVERSION=	6.el6_5
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libtasn1.so.3 usr/lib/libtasn1.so.3.1.6
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING COPYING.LIB ChangeLog NEWS README THANKS TODO libtasn1.pdf
DESCR=		${.CURDIR}/../libtasn1/pkg-descr

.include <bsd.port.mk>
