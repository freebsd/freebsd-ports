# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-FormatText-WithLinks-AndTables
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to convert HTML to text with tables in tact

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Format>=0:textproc/p5-HTML-Format \
		p5-HTML-FormatText-WithLinks>=0:textproc/p5-HTML-FormatText-WithLinks \
		p5-HTML-Tree>=0:www/p5-HTML-Tree
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
