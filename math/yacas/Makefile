# ex:ts=8
# New ports collection makefile for:	yacas
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yacas
PORTVERSION=	1.2.2
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	http://yacas.sourceforge.net/backups/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

USE_AUTOTOOLS=	libtool
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--enable-html-doc --with-html-dir=${DOCSDIR}
.else
CONFIGURE_ARGS+=	--disable-html-doc
.endif

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

test:	build
	@cd ${WRKSRC} && ${GMAKE} test

.include <bsd.port.post.mk>
