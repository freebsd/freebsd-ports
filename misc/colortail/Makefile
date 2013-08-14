# New ports collection makefile for:   colortail
# Date created:                25 February 1999
# Whom:                        Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	colortail
PORTVERSION=	0.3.3
CATEGORIES=	misc
MASTER_SITES=	http://joakimandersson.se/files/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A colour-able replacement for tail(1)


GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example-conf/conf* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
