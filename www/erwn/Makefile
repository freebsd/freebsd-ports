# New ports collection makefile for:	erwin
# Date created:			31 July 1999
# Whom:				Jim Mock <jimFreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	erwn
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	www editors
MASTER_SITES=	http://lisas.de/erwin/
DISTNAME=	erwin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK+-2 HTML editor

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libgtkhtml gtksourceview
GNU_CONFIGURE=	yes

MAN1=	erwin.1

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
