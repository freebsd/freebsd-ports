# ex:ts=8
# New ports collection makefile for:	salias
# Date created:			May 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	salias
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

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
