# New ports collection makefile for:	p5-WWW-NioTV
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	WWW-NioTV
PORTVERSION=	0.04
DISTVERSIONPREFIX=v
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve TV information from http://www.niotv.com/

RUN_DEPENDS=	p5-HTML-SimpleLinkExtor>=1.19:${PORTSDIR}/www/p5-HTML-SimpleLinkExtor \
		p5-HTML-TableExtract>=2.1:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0.54:${PORTSDIR}/devel/p5-Moose \
		p5-WWW-Mechanize>=1.34:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-version>=0.76:${PORTSDIR}/devel/p5-version

PERL_CONFIGURE=	yes

MAN3=		WWW::NioTV.3

.include <bsd.port.mk>
