# ex:ts=8
# Ports collection makefile for:	cave
# Date created:			Dec 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cave
PORTVERSION=	1.0b
CATEGORIES=	misc
MASTER_SITES=	http://arbornet.org/~bjk/cave/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character Animation Viewer for Everyone

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		cave.1
PLIST_FILES=	bin/cave

pre-build:
	${CP} ${WRKSRC}/doc/cave.man ${WRKSRC}/doc/cave.1

.include <bsd.port.mk>
