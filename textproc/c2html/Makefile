# New ports collection makefile for:	c2html
# Date created:				28 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		c2html
PORTVERSION=		0.9.2
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net
COMMENT=	C-language sources to HTML converter

USE_AUTOCONF_VER=	213

MAN1=			c2html.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/c2html
.for file in AUTHORS NEWS README
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/c2html
.endfor
.endif

.include <bsd.port.mk>
