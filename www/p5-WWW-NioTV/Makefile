# New ports collection makefile for:	p5-WWW-NioTV
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	WWW-NioTV
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Retrieve TV information from http://www.niotv.com/

BUILD_DEPENDS=	p5-HTML-SimpleLinkExtor>=0:${PORTSDIR}/www/p5-HTML-SimpleLinkExtor \
		p5-HTML-TableExtract>=0:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0.25:${PORTSDIR}/devel/p5-Moose \
		p5-version>=0:${PORTSDIR}/devel/p5-version \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::NioTV.3

.include <bsd.port.mk>
