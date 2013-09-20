# Created by: Martin Kammerhofer
# $FreeBSD$

PORTNAME=		java2html
PORTVERSION=		0.9.2
PORTREVISION=		1
CATEGORIES=		textproc www
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=		mkamm@gmx.net
COMMENT=	Java sources to HTML converter

USE_AUTOTOOLS=	autoconf213

MAN1=			java2html.1

.if !defined(NOPORTDOCS)
NO_STAGE=	yes
post-install:
	${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
