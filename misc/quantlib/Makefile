# ex:ts=8
# New ports collection makefile for:	quantlib
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	quantlib
PORTVERSION=	0.2.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	QuantLib-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/QuantLib-${PORTVERSION}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=		DiscreteHedging.1 EuropeanOption.1 SwapValuation.1 \
		quantlib-config.1

post-patch:
	@${PERL} -pi -e 's|-g -Wall -O2|\$$CXXFLAGS|g' ${WRKSRC}/configure
	@find ${WRKSRC}/Examples -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|-g -O2 -Wall|\@CXXFLAGS\@ -O0|g'

.include <bsd.port.mk>
