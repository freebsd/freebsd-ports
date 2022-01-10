# Created by: Dmitry Morozovsky <marck@FreeBSD.org>

PORTNAME=	XML-Driver-HTML
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl SAX Driver for non wellformed HTML

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-TreeBuilder>=0:textproc/p5-XML-TreeBuilder \
		p5-XML-Handler-YAWriter>=0:textproc/p5-XML-Handler-YAWriter

USES=		perl5
USE_PERL5=	configure

CONFLICTS_INSTALL=	html2xhtml p5-HTML-HTML5-Parser # bin/html2xhtml

.include <bsd.port.mk>
