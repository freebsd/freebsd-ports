# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Amazon-S3
PORTVERSION=	0.80
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use the Amazon S3 - Simple Storage Service

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-Stream-Bulk>=0.06:devel/p5-Data-Stream-Bulk \
		p5-DateTime-Format-HTTP>=0:devel/p5-DateTime-Format-HTTP \
		p5-DateTime-Format-ISO8601>=0:devel/p5-DateTime-Format-ISO8601 \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-Digest-MD5-File>=0:security/p5-Digest-MD5-File \
		p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined \
		p5-Moose>=2:devel/p5-Moose \
		p5-MooseX-StrictConstructor>=0.16:devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types-DateTime-MoreCoercions>=0.07:devel/p5-MooseX-Types-DateTime-MoreCoercions \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-URI>=0:net/p5-URI \
		p5-VM-EC2-Security-CredentialCache>=0:net/p5-VM-EC2-Security-CredentialCache \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-libwww>=6.03:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
