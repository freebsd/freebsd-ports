# New ports collection makefile for:	liblbfgs
# Date created:		2010-06-08
# Whom:			Hung-Yi Chen <gaod@hychen.org>
#
# $FreeBSD$
#

PORTNAME=	liblbfgs
PORTVERSION=	1.9
CATEGORIES=	math
MASTER_SITES=	http://www.chokkan.org/software/dist/

MAINTAINER=	gaod@hychen.org
COMMENT=	A library of Limited-memory Broyden-Fletcher-Goldfarb-Shanno

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262:env

OPTIONS=	OPTIMIZED "Enable SSE2 optimization routines" Off

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 700000)
IGNORE=	does not install properly on 6.x
.endif

# Enable/disable compilation optimizations.
.if defined(WITH_OPTIMIZED)
CONFIGURE_ARGS+=	--enable-sse2
.endif

PLIST_FILES=	lib/liblbfgs-1.9.so.0.0 lib/liblbfgs.a lib//liblbfgs.la \
		lib/liblbfgs.so.0.0 include/lbfgs.h

PORTDOCS=	README INSTALL COPYING AUTHORS ChangeLog NEWS

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/install-data-am$$//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
