# New ports collection makefile for:    libvmime
# Date created:				September 17, 2005
# Whom:					delphij@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libvmime
PORTVERSION=	0.7.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vmime

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	An all-in-one Internet mail library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GCC=	3.3+
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--disable-debug

DOCSDIR=	${PREFIX}/share/doc/vmime

.include <bsd.port.mk>
