# New ports collection makefile for:	java2html
# Date created:				21 March 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=		java2html
PORTVERSION=		0.9.2
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net
COMMENT=	Java sources to HTML converter

USE_AUTOCONF_VER=	213

MAN1=			java2html.1

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/java2html
.for file in AUTHORS NEWS README
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/java2html
.endfor
.endif

.include <bsd.port.mk>
