# New ports collection makefile for:   ctpp
# Date created:         19 July 2004
# Whom:                 shetuhin@corp.mail.ru (Andrei V. Shetuhin)
#
# $FreeBSD$
#

PORTNAME=	ctpp
PORTVERSION=	1.7.5
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.reki.ru/products/ctpp/download/

MAINTAINER=	shetuhin@corp.mail.ru
COMMENT=	C++ library to use templates in C/C++ projects

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

.if defined(WITH_CTPP_PERF_TUNING)
CONFIGURE_ARGS+=	--enable-optimization
.endif

.if defined(WITH_CTPP_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${RM} -f ${WRKSRC}/obj/*.o

.include <bsd.port.mk>
