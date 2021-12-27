# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	Net-Amazon-S3
PORTVERSION=	0.99
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use the Amazon S3 - Simple Storage Service

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-Stream-Bulk>=0.06:devel/p5-Data-Stream-Bulk \
		p5-DateTime-Format-HTTP>=0:devel/p5-DateTime-Format-HTTP \
		p5-DateTime-Format-ISO8601>=0:devel/p5-DateTime-Format-ISO8601 \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-Digest-MD5-File>=0:security/p5-Digest-MD5-File \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined \
		p5-MIME-Types>=0:mail/p5-MIME-Types \
		p5-Moose>=2:devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-StrictConstructor>=0.16:devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types-DateTime-MoreCoercions>=0.07:devel/p5-MooseX-Types-DateTime-MoreCoercions \
		p5-Ref-Util>=0:devel/p5-Ref-Util \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Sub-Override>=0:devel/p5-Sub-Override \
		p5-Term-Encoding>=0:devel/p5-Term-Encoding \
		p5-Term-ProgressBar-Simple>=0:devel/p5-Term-ProgressBar-Simple \
		p5-Test-Deep>=0.111.0:devel/p5-Test-Deep \
		p5-Test-LWP-UserAgent>=0:www/p5-Test-LWP-UserAgent \
		p5-URI>=0:net/p5-URI \
		p5-VM-EC2-Security-CredentialCache>=0:net/p5-VM-EC2-Security-CredentialCache \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-libwww>=6.03:www/p5-libwww
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-MockTime>=0:devel/p5-Test-MockTime \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
