# New ports collection makefile for:	thewidgetfactory
# Date created:				12 October 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thewidgetfactory
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.stellingwerff.com/TheWidgetFactory/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for previewing GTK+ widgets and testing new themes

USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/twf
PORTDOCS=	AUTHORS COPYING ChangeLog README

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
