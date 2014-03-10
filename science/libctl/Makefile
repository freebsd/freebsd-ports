# Created by: ijliao
# $FreeBSD$

PORTNAME=	libctl
PORTVERSION=	3.2.1
PORTREVISION=	2
CATEGORIES=	science math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	devel@stasyan.com
COMMENT=	Control Language Library

LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile

USES=		fortran
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build
.endif

.if ${ARCH} == i386 && ${OSVERSION} < 901000
BROKEN=		does not link due to libtool not respecting CC
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
