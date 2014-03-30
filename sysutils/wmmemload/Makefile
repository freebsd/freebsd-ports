# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmmemload
PORTVERSION=	0.1.6
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	xride

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An dockapp for windowmaker that displays the current mem/swap usage

BROKEN=		Fails to configure
EXPIRATION_DATE=	2014-05-01

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	xpm
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		wmmemload.1

NO_STAGE=	yes
post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
