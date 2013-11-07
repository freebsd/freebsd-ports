# Created by: Fanying Jen <fanying@fynet.com>
# $FreeBSD$

PORTNAME=	WWW-Search-AltaVista
PORTVERSION=	2.154
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl WWW::Search class for searching AltaVista

BUILD_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-WWW-Search>=0:${PORTSDIR}/www/p5-WWW-Search
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
