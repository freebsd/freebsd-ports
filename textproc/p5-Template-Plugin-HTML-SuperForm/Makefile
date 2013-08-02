# Created by: Philip M. Goillucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	Template-Plugin-HTML-SuperForm
PORTVERSION=	1.0
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface Template Toolkit to Lingua::EN::Inflect module

RUN_DEPENDS=	p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
  				p5-HTML-SuperForm>0:${PORTSDIR}/textproc/p5-HTML-SuperForm

USES=		perl5
USE_PERL5=	configure

WRKSRC=	${WRKDIR}/${PORTNAME}

MAN3=	Template::Plugin::HTML::SuperForm.3

.include <bsd.port.mk>
