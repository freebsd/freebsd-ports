# ex:ts=8
# Ports collection Makefile for:	libctl
# Date created:			Apr 4, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libctl
PORTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	science math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Control Language Library

LIB_DEPENDS=	guile.18:${PORTSDIR}/lang/guile

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV+=	 FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"
USE_FORTRAN=	yes
USE_LDCONFIG=	yes

MAN1=		gen-ctl-io.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
