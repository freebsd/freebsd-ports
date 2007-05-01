# New ports collection makefile for:	p5-SOAP-Amazon-S3
# Date created:		2007-04-30
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	SOAP-Amazon-S3
PORTVERSION=	0.023
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	SOAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A module for interfacing with Amazon S3 through SOAP

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece \
		${SITE_PERL}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/SOAP/MySOAP.pm:${PORTSDIR}/net/p5-SOAP-MySOAP \
		${SITE_PERL}/XML/MyXML.pm:${PORTSDIR}/textproc/p5-XML-MyXML

PERL_CONFIGURE=	yes

MAN3=		SOAP::Amazon::S3.3

.include <bsd.port.mk>
