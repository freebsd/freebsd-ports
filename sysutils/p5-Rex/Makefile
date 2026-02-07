PORTNAME=	Rex
PORTVERSION=	1.16.1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FERKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Friendly automation framework
WWW=		https://metacpan.org/release/Rex \
		https://www.rexify.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-AWS-Signature4>=0:devel/p5-AWS-Signature4 \
		p5-Data-Validate-IP>=0:net-mgmt/p5-Data-Validate-IP \
		p5-Devel-Caller>=0:devel/p5-Devel-Caller \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-IO-Tty>=0:devel/p5-IO-Tty \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Net-OpenSSH>=0:net/p5-Net-OpenSSH \
		p5-Net-SFTP-Foreign>=0:net/p5-Net-SFTP-Foreign \
		p5-Sort-Naturally>=0:textproc/p5-Sort-Naturally \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Text-Glob>=0:textproc/p5-Text-Glob \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-YAML>=0:textproc/p5-YAML \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-String-Escape>=0:textproc/p5-String-Escape \
		p5-Sub-Override>=0:devel/p5-Sub-Override \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-UseAllModules>=0.15:devel/p5-Test-UseAllModules \
		p5-Test-Warnings>=0.033:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>
