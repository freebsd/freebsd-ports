# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-IMAP-Server
PORTVERSION=	1.38
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Single-threaded multiplexing IMAP server implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Coro>0:${PORTSDIR}/devel/p5-Coro \
		p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Mail>0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-Strptime>=1.3:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Email-Address>0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Email-MIME>=1.862:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Simple>=1.999:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Encode-IMAPUTF7>0:${PORTSDIR}/converters/p5-Encode-IMAPUTF7 \
		p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Net-Server-Coro>=0.6:${PORTSDIR}/net/p5-Net-Server-Coro \
		p5-Regexp-Common>0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-Socket-SSL>0:${PORTSDIR}/security/p5-IO-Socket-SSL

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
