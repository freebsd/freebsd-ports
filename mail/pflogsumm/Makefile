# New ports collection makefile for:	pflogsumm
# Date created:				13 April 2001
# Whom:					Sergey Osokin aka oZZ <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pflogsumm
PORTVERSION=	1.0.7
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://jimsun.LinxNet.com/downloads/ \
		ftp://jimsun.LinxNet.com/pub/postfix_contrib/

MAINTAINER=	erwin@lansing.dk

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc

NO_BUILD=	yes
USE_PERL5=	yes

MAN1=		pflogsumm.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
