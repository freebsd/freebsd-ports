# New ports collection makefile for:	erwin
# Date created:			31 July 1999
# Whom:				Jim Mock <jimFreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	erwn
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	www editors
MASTER_SITES=	http://lisas.de/erwin/
DISTNAME=	erwin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple (at the moment) html editor based on GTK+

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libxml2 libgtkhtml
USE_LIBTOOL=	yes

MAN1=	erwin.1

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
