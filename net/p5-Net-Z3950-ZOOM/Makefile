PORTNAME=	Net-Z3950-ZOOM
PORTVERSION=	1.30
PORTREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl interface to the Z39.50 Object-Orientation Model (ZOOM)
WWW=		https://metacpan.org/release/Net-Z3950-ZOOM

LIB_DEPENDS=	libyaz.so:net/yaz
BUILD_DEPENDS=	p5-MARC-Record>=1.38:textproc/p5-MARC-Record
RUN_DEPENDS=	p5-MARC-Record>=1.38:textproc/p5-MARC-Record

USES=		perl5
USE_PERL5=	configure

CONFLICTS=	p5-Net-Z3950

.include <bsd.port.mk>
