# New ports collection makefile for:	SOAP
# Date created:				Wed Jan  3 10:01:46 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	SOAP
PORTVERSION=	0.28
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SOAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl modules providing an API to the Simple Object Access Protocol

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SOAP.3 SOAP::SimpleTypeWrapper.3 SOAP::Parser.3 \
		SOAP::EnvelopeMaker.3 SOAP::GenericScalarSerializer.3 \
		SOAP::Transport::HTTP::Apache.3 SOAP::TypedPrimitiveSerializer.3 \
		SOAP::GenericInputStream.3 SOAP::Serializer.3 \
		SOAP::GenericHashSerializer.3 SOAP::OutputStream.3 \
		SOAP::Transport::HTTP::CGI.3 SOAP::Packager.3 SOAP::Envelope.3 \
		SOAP::TypedPrimitive.3 SOAP::StructSerializer.3 \
		SOAP::Transport::HTTP::Server.3 SOAP::Defs.3 SOAP::Struct.3 \
		SOAP::TypeMapper.3 SOAP::Transport::HTTP::Client.3

.include <bsd.port.mk>
