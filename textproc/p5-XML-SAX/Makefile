# New ports collection makefile for:	XML::SAX
# Date created:		19 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX
PORTVERSION=	0.96
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Simple API for XML

RUN_DEPENDS=	${SITE_PERL}/XML/NamespaceSupport.pm:${PORTSDIR}/textproc/p5-XML-NamespaceSupport
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

MAN3=		XML::SAX.3 XML::SAX::Base.3 XML::SAX::DocumentLocator.3 \
		XML::SAX::Exception.3 XML::SAX::Intro.3 \
		XML::SAX::ParserFactory.3 XML::SAX::PurePerl.3 \
		XML::SAX::PurePerl::Reader.3

post-configure:
# dirty hack to deceive irritable pod2man
		@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' \
				${WRKSRC}/Makefile

.include <bsd.port.mk>
