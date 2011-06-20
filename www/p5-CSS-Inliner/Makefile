# New ports collection makefile for:    p5-HTML-Query
# Date created:                         Sat Oct 10 17:28:20 EDT 2009
# Whom:                                 Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	CSS-Inliner
PORTVERSION=	3275
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Library for converting CSS blocks and files to inline styles

RUN_DEPENDS=	p5-CSS-Simple>=3211:${PORTSDIR}/textproc/p5-CSS-Simple \
		p5-HTML-Query>=0.07:${PORTSDIR}/www/p5-HTML-Query \
		p5-HTML-Tree>=3.23:${PORTSDIR}/www/p5-HTML-Tree \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1

PERL_CONFIGURE=	yes

MAN3=		CSS::Inliner.3
PLIST_FILES=	%%SITE_PERL%%/CSS/Inliner.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/CSS/Inliner/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/CSS/Inliner

.include <bsd.port.mk>
