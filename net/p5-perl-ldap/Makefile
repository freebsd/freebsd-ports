# Created by: scrappy@FreeBSD.org
# $FreeBSD$

PORTNAME=	perl-ldap
PORTVERSION=	0.6500
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARSCHAP
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/00$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client interface to LDAP (includes Net::LDAP)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Authen-SASL>=2.00:security/p5-Authen-SASL \
		p5-Convert-ASN1>=0.20:converters/p5-Convert-ASN1 \
		p5-IO-Socket-SSL>=1.26:security/p5-IO-Socket-SSL \
		p5-URI>=1.10:net/p5-URI \
		p5-XML-SAX-Base>0:textproc/p5-XML-SAX-Base \
		p5-XML-SAX-Writer>0:textproc/p5-XML-SAX-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	LWP
LWP_DESC=	LDAP support via LWP
LWP_BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
			p5-LWP-MediaTypes>=0:www/p5-LWP-MediaTypes \
			p5-HTTP-Negotiate>=0:www/p5-HTTP-Negotiate \
			p5-HTTP-Message>=0:www/p5-HTTP-Message \
			p5-JSON>=0:converters/p5-JSON
LWP_RUN_DEPENDS:=	${LWP_BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
