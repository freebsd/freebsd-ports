# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-IMAP-Simple
PORTVERSION=	1.2204
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JETTERO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for simple IMAP account handling

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Coro>=0:${PORTSDIR}/devel/p5-Coro \
		p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Email-MIME-ContentType>=0:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		p5-Email-MIME>=1.862:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Simple>=1.999:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Encode-IMAPUTF7>=0:${PORTSDIR}/converters/p5-Encode-IMAPUTF7 \
		p5-IO-Socket-SSL>0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Net-Server-Coro>=0.3:${PORTSDIR}/net/p5-Net-Server-Coro \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	SX
OPTIONS_SUB=	yes
SX_DESC=	Simple protocol extensions (use Parse::RecDescent)

PORTSCOUT=	skipv:1.20271

USES=		perl5
USE_PERL5=	configure

SX_BUILD_DEPENDS=	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
SX_CONFIGURE_ENV=	WITH_SX=true
SX_RUN_DEPENDS=		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
