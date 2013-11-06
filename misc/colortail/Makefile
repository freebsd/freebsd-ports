# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	colortail
PORTVERSION=	0.3.3
CATEGORIES=	misc
MASTER_SITES=	http://joakimandersson.se/files/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	tail(1) replacement with color support

LICENCE=	GPLv2

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colortail ${STAGEDIR}${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example-conf/conf* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
