# New ports collection makefile for:	p5-HTML-TableExtract
# Date created:				October 21th 2000
# Whom:					Sergey Osokin aka oZZ <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-TableExtract
PORTVERSION=	1.08
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::TableExtract.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
