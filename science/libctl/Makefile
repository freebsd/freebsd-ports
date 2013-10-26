# Created by: ijliao
# $FreeBSD$

PORTNAME=	libctl
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	science math
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	devel@stasyan.com
COMMENT=	Control Language Library

LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile

USE_AUTOTOOLS=	libtool
USE_FORTRAN=	yes
USE_LDCONFIG=	yes

MAN1=		gen-ctl-io.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build
.endif

.if ${ARCH} == i386 && ${OSVERSION} < 901000
BROKEN=		does not link due to libtool not respecting CC
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
