# ex:ts=8
# Ports collection Makefile for:	libctl
# Date created:			Apr 4, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libctl
PORTVERSION=	2.2
CATEGORIES=	science math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Control Language Library

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes

MAN1=	gen-ctl-io.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
