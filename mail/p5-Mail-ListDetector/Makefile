# Created by: petef
# $FreeBSD$

PORTNAME=	Mail-ListDetector
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSTEVENS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for detecting mailing list messages

RUN_DEPENDS=	p5-Email-Abstract>=3.001:mail/p5-Email-Abstract \
		p5-Email-Valid>=0.182:mail/p5-Email-Valid \
		p5-Mail-Tools>=2.04:mail/p5-Mail-Tools \
		p5-URI>=1.1:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	examples/sample.pl
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/sample.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
