# New ports collection makefile for:   colortail
# Date created:                25 February 1999
# Whom:                        Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	colortail
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.student.hk-r.se/~pt98jan/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A colour-able replacement for tail(1)

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example-conf/conf* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
