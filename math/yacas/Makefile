# ex:ts=8
# New ports collection makefile for:	yacas
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yacas
PORTVERSION=	1.0.54
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://yacas.sourceforge.net/backups/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_GMP)
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif
CONFIGURE_ARGS+=	--enable-gmp=yes
.endif

.include <bsd.port.post.mk>
