# New ports collection makefile for:	p5-CGI
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-modules
PORTVERSION=	2.76
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modules for perl5, for use in writing CGI scripts

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		CGI::Base.3 CGI::BasePlus.3 CGI::Carp.3 CGI::Form.3 \
		CGI::MiniSvr.3 CGI::Request.3

post-patch:
	@${RM} ${WRKSRC}/CGI/*.orig

.include <bsd.port.mk>
