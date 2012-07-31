# New ports collection makefile for:	bulk_extractor
# Date created:		31 May 2012
# Whom:			MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bulk_extractor
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/simsong/bulk_extractor/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A program that scans a disk image and extracts useful information

LICENSE=	PD
LICENSE_NAME=	public domain
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

LIB_DEPENDS=	afflib:${PORTSDIR}/sysutils/afflib \
		ewf:${PORTSDIR}/devel/libewf \
		exiv2:${PORTSDIR}/graphics/exiv2 \
		expat:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	autoconf
USE_OPENSSL=	yes
USE_PYTHON=	yes

MAN1=		bulk_extractor.1

PLIST_FILES=	bin/bulk_extractor

.include <bsd.port.mk>
