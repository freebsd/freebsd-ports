# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	Net-Patricia
PORTVERSION=	1.22
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for fast IP address lookups

BUILD_DEPENDS=	p5-Net-CIDR-Lite>=0.20:${PORTSDIR}/net/p5-Net-CIDR-Lite
RUN_DEPENDS=	p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6

MAKE_JOBS_UNSAFE=yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
