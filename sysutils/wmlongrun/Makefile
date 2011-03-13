# New ports collection makefile for:	wmlongrun
# Date created:				Sat Mar 23 21:00:03 EST 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmlongrun
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://seiichisato.jp/dockapps/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp to monitor the LongRun(tm) status on Crusoe

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_XORG=	xpm
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

MAN1=		wmlongrun.1
PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/wmlongrun

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
