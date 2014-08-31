# Created by: ijliao
# $FreeBSD$

PORTNAME=	libctl
PORTVERSION=	3.2.1
PORTREVISION=	4
CATEGORIES=	science math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	devel@stasyan.com
COMMENT=	Control Language Library

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USES=		fortran libtool
USE_LDCONFIG=	yes

BROKEN_sparc64=	does not build

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
