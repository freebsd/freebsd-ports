# New ports collection makefile for:   colortail
# Date created:                25 February 1999
# Whom:                        Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	colortail
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A colour-able replacement for tail(1)

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example-conf/conf* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
