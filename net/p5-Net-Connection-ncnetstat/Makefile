# Created by: Zane C. Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Net-Connection-ncnetstat
PORTVERSION=	0.7.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Netstat like utility that supports color and searching

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-Connection>=0.2.0:net/p5-Net-Connection \
		p5-Net-Connection-Match>=0.5.0:net/p5-Net-Connection-Match \
		p5-Net-Connection-Sort>=0.0.1:net/p5-Net-Connection-Sort \
		p5-Term-ANSIColor>=4.06:devel/p5-Term-ANSIColor \
		p5-Text-ANSITable>=0.601:textproc/p5-Text-ANSITable \
		p5-Getopt-Long>=2.52:devel/p5-Getopt-Long \
		p5-Data-Unixish>=1.570:devel/p5-Data-Unixish \
		p5-Net-Connection-lsof>=0.2.0:net/p5-Net-Connection-lsof

USES=		perl5 shebangfix
USE_PERL5=	configure

.include <bsd.port.mk>
