# New ports collection makefile for:	pflogsumm
# Date created:				13 April 2001
# Whom:					Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	pflogsumm
PORTVERSION=	20000916.01
CATEGORIES=	mail pflogsumm
MASTER_SITES=	http://jimsun.LinxNet.com/downloads/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pl

MAINTAINER=	ozz@FreeBSD.org.ru

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 0755 ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
