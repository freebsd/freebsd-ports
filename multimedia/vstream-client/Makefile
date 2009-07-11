# New ports collection makefile for:    vstream-client
# Date created:				2005-10-06
# Whom:					Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	vstream-client
PORTVERSION=	1.2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.nicewarrior.org/${PORTNAME}/ \
		http://www.exit.com/Archives/FreeBSD/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The vstream library from the tivo-mplayer project

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/vstream-client \
		lib/libvstream-client.a \
		include/vstream-client.h

.include <bsd.port.mk>
