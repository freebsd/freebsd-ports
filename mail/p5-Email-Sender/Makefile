# Created by: Bill Brinzer <bill.brinzer@gmail.com>
# $FreeBSD$

PORTNAME=	Email-Sender
PORTVERSION=	1.300006
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Library for sending email

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Abstract>=3:${PORTSDIR}/mail/p5-Email-Abstract \
		p5-Email-Address>=0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Email-Simple>=1.998:${PORTSDIR}/mail/p5-Email-Simple \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Module-Runtime>=0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Moo>=1.000008:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0.15:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sys-Hostname-Long>=0:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-Throwable>=0.200003:${PORTSDIR}/devel/p5-Throwable
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0.08:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Sub-Override>=0:${PORTSDIR}/devel/p5-Sub-Override \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
