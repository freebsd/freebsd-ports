# New ports collection makefile for:	bsdsfv
# Date created:				26 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	bsdsfv
PORTVERSION=	1.18
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A flexible SFV checksum utility

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/bsdsfv
PORTDOCS=	MANUAL

post-patch:
	@${REINPLACE_CMD} -e 's|^\(INSTALL_PREFIX =\).*$$|\1 ${PREFIX}|g' \
		${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
