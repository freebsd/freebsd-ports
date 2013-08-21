# New ports collection makefile for:	p5-Protocol-XMLRPC
# Date created:		2011-09-24
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Protocol-XMLRPC
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VTI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XML-RPC implementation

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML

USE_PERL5=	configure
USES=		perl5

MAN3=		Protocol::XMLRPC.3 \
		Protocol::XMLRPC::Client.3 \
		Protocol::XMLRPC::Method.3 \
		Protocol::XMLRPC::MethodCall.3 \
		Protocol::XMLRPC::MethodResponse.3 \
		Protocol::XMLRPC::Value.3 \
		Protocol::XMLRPC::Value::Array.3 \
		Protocol::XMLRPC::Value::Base64.3 \
		Protocol::XMLRPC::Value::Boolean.3 \
		Protocol::XMLRPC::Value::DateTime.3 \
		Protocol::XMLRPC::Value::Double.3 \
		Protocol::XMLRPC::Value::Integer.3 \
		Protocol::XMLRPC::Value::String.3 \
		Protocol::XMLRPC::Value::Struct.3 \
		Protocol::XMLRPC::ValueFactory.3

.include <bsd.port.mk>
