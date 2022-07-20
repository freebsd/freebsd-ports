PORTNAME=	Amazon-SQS-Simple
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SWHITAKER
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	OO API for accessing the Amazon Simple Queue Service

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

SUB_FILES=	pkg-message

.include <bsd.port.mk>
