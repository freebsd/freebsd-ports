PORTNAME=	jQuery-File-Upload
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for jQuery File Upload plugin
WWW=		https://metacpan.org/release/jQuery-File-Upload

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-Data-GUID>=0:devel/p5-Data-GUID \
		p5-JSON>=0:converters/p5-JSON \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Net-SSH2>=0:net/p5-Net-SSH2 \
		p5-URI>=0:net/p5-URI

USES=		magick:6,run perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include	<bsd.port.mk>
