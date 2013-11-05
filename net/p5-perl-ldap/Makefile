# Created by: scrappy@FreeBSD.org
# $FreeBSD$

PORTNAME=	perl-ldap
PORTVERSION=	0.5700
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARSCHAP
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/00$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client interface to LDAP (includes Net::LDAP)

BUILD_DEPENDS=	p5-Authen-SASL>=2.00:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Convert-ASN1>=0.20:${PORTSDIR}/converters/p5-Convert-ASN1 \
		p5-IO-Socket-SSL>=1.26:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-URI>=1.10:${PORTSDIR}/net/p5-URI \
		p5-XML-SAX-Base>0:${PORTSDIR}/textproc/p5-XML-SAX-Base \
		p5-XML-SAX-Writer>0:${PORTSDIR}/textproc/p5-XML-SAX-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
