# New ports collection makefile for:	p5-HTML-Seamstress
# Date created:				2007/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	HTML-Seamstress
PORTVERSION=	5.0h
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML::Tree subclass for HTML templating via tree rewriting

BUILD_DEPENDS=	p5-Class-Prototyped>=0:${PORTSDIR}/devel/p5-Class-Prototyped \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-HTML-Element-Library>=0:${PORTSDIR}/www/p5-HTML-Element-Library \
		p5-HTML-PrettyPrinter>=0:${PORTSDIR}/www/p5-HTML-PrettyPrinter \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN1=		sbase.pl.1 \
		spkg.pl.1
MAN3=		HTML::Seamstress.3 \
		HTML::Seamstress::Doc::FAQ.3 \
		HTML::Seamstress::EDIT_Quickstart.tt_DO_NOT_EDIT_Quickstart.3 \
		HTML::Seamstress::Quickstart.3 \
		HTML::sbase.3 \
		HTML::spkg.3 \
		XML::Seamstress.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
