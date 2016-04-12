# Created by: glarkin
# $FreeBSD$

PORTNAME=	Net-Mosso-CloudFiles
PORTVERSION=	0.44
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl interface to the Mosso CloudFiles service

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-Data-Stream-Bulk>=0:devel/p5-Data-Stream-Bulk \
		p5-DateTime-Format-HTTP>=0:devel/p5-DateTime-Format-HTTP \
		p5-Digest-MD5-File>=0:security/p5-Digest-MD5-File \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-JSON-XS-VersionOneAndTwo>=0:converters/p5-JSON-XS-VersionOneAndTwo \
		p5-LWP-ConnCache-MaxKeepAliveRequests>=0:www/p5-LWP-ConnCache-MaxKeepAliveRequests \
		p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-StrictConstructor>=0:devel/p5-MooseX-StrictConstructor \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
