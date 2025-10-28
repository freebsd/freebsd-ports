PORTNAME=	Firefox-Marionette
DISTVERSION=	1.68
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DDICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Automate the Firefox browser with the Marionette protocol
WWW=		https://metacpan.org/release/Firefox-Marionette

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	firefox>0:www/firefox \
		p5-Crypt-PasswdMD5>=0:security/p5-Crypt-PasswdMD5 \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-HTTP-Daemon>=0:www/p5-HTTP-Daemon \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-PDF-API2>=2.036:textproc/p5-PDF-API2
RUN_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Config-INI>=0:devel/p5-Config-INI \
		p5-Crypt-URandom>=0:security/p5-Crypt-URandom \
		p5-JSON>=0:converters/p5-JSON \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Text-CSV_XS>=1.35:textproc/p5-Text-CSV_XS \
		p5-URI>=1.61:net/p5-URI \
		p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
