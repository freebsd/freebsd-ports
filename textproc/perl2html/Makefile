# New ports collection makefile for:	perl2html
# Date created:				27 May 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=		perl2html
PORTVERSION=		0.9.2
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net
COMMENT=	Perl sources to HTML converter

USE_AUTOCONF_VER=	213

MAN1=			perl2html.1

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/perl2html
.for file in AUTHORS NEWS README
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/perl2html
.endfor
.endif

.include <bsd.port.mk>
