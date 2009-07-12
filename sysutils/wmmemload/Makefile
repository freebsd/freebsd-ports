# New ports collection makefile for:	wmmemload
# Date created:				14 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmmemload
PORTVERSION=	0.1.6
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	xride

MAINTAINER=	xride@FreeBSD.org
COMMENT=	An dockapp for windowmaker that displays the current mem/swap usage

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	xpm
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		wmmemload.1

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
