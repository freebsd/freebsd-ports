# New ports collection makefile for:	perl2html
# Version required:			0.6.1
# Date created:				27 May 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

DISTNAME=		perl2html-0.6.3
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net

USE_AUTOCONF=		yes

MAN1=			perl2html.1

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/perl2html
.for file in AUTHORS NEWS README
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/perl2html
.endfor
.endif

.include <bsd.port.mk>
