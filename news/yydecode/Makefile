# New ports collection makefile for: yydecode
# Date created:		14 Dec 2004
# Whom:			Mikolaj Rydzewski <miki@ceti.pl>
#
# $FreeBSD$
#

PORTNAME=	yydecode
PORTVERSION=	0.2.10
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	yydecode

MAINTAINER=	miki@ceti.pl
COMMENT=	Tool to decode yEnc encoded files

MAN1=		yydecode.1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/yydecode

.include <bsd.port.mk>
