# ex:ts=8
# New ports collection makefile for:	salias
# Date created:			May 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	salias
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/C%20${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command-line tool to alias arguments of other programs

USE_BZIP2=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

MAN1=		salias.1
DOCS=		NEWS README

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
