# New ports collection makefile for:    vstream-client
# Date created:				2005-10-06
# Whom:					Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	vstream-client
PORTVERSION=	1.2
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The vstream library from the tivo-mplayer project

USE_BZIP2=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/vstream-client \
		lib/libvstream-client.a \
		include/vstream-client.h

.include <bsd.port.mk>
