# New ports collection makefile for:	pure-xml
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-xml
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface for libxml2 and libxslt

USE_PURE=	yes
USE_GNOME=	libxml2 libxslt

PLIST_FILES=	lib/pure/xml.pure \
		lib/pure/xml.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.post.mk>
