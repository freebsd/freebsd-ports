# New ports collection makefile for:	pflogsumm
# Date created:				13 April 2001
# Whom:					Sergey Osokin aka oZZ <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pflogsumm
PORTVERSION=	1.0.3
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://jimsun.LinxNet.com/downloads/ \
		ftp://jimsun.LinxNet.com/pub/postfix_contrib/
EXTRACT_SUFX=	.pl

MAINTAINER=	erwin@lansing.dk

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_PERL5=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} \
		${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
