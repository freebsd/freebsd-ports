# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-SAX-Expat
PORTVERSION=	0.50
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple API for XML

RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-NamespaceSupport>=0:${PORTSDIR}/textproc/p5-XML-NamespaceSupport
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure patch

post-patch:
		@${PERL} -pi -e "s/(?<=XML::SAX::Base          => ')1\.00(?=')/0.25/;" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
