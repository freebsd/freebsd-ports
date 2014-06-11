# Created by: Sylvio Cesar Teixeira <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ftasv
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://fabletech.com/${PORTNAME}-download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Is a commandline scoreboard viewer for the Apache server

GNU_CONFIGURE=	yes
USE_APACHE=	22+

PLIST_FILES=	sbin/ftasv
SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS COPYING ChangeLog README

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not link on 6.X
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
