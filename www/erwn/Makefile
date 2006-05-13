# New ports collection makefile for:	erwin
# Date created:			31 July 1999
# Whom:				Jim Mock <jimFreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	erwn
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	www editors
MASTER_SITES=	http://lisas.de/erwin/
DISTNAME=	erwin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK+-2 HTML editor

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtkhtml3 gtksourceview
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		erwin.1

post-patch:
	@${REINPLACE_CMD} -e "s|gtkhtml-3.6|gtkhtml-3.8|g" \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
