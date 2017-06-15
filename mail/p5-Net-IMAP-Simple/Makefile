# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-IMAP-Simple
PORTVERSION=	1.2207
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JETTERO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for simple IMAP account handling

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Coro>=0:devel/p5-Coro \
		p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-Email-Address>=0:mail/p5-Email-Address \
		p5-Email-MIME-ContentType>=0:mail/p5-Email-MIME-ContentType \
		p5-Email-MIME>=1.862:mail/p5-Email-MIME \
		p5-Email-Simple>=1.999:mail/p5-Email-Simple \
		p5-Encode-IMAPUTF7>=0:converters/p5-Encode-IMAPUTF7 \
		p5-IO-Socket-SSL>0:security/p5-IO-Socket-SSL \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-MIME-Base64>=0:converters/p5-MIME-Base64 \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-Net-Server-Coro>=0.3:net/p5-Net-Server-Coro \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	SX
OPTIONS_SUB=	yes
SX_DESC=	Simple protocol extensions (use Parse::RecDescent)

PORTSCOUT=	skipv:1.20271

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

SX_BUILD_DEPENDS=	p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent
SX_CONFIGURE_ENV=	WITH_SX=true
SX_RUN_DEPENDS=		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent

.include <bsd.port.mk>
