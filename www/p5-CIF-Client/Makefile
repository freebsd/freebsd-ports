# Created by: pauls@utdallas.edu
# $FreeBSD$

PORTNAME=	CIF-Client
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAXJAZMAN/cif
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extends REST::Client for use with the CI-Framework REST interface

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.31:devel/p5-Class-Accessor \
		p5-Compress-Raw-Zlib>=2.008:archivers/p5-Compress-Raw-Zlib \
		p5-Config-Simple>=4.58:devel/p5-Config-Simple \
		p5-Digest-SHA1>=2.11:security/p5-Digest-SHA1 \
		p5-Digest-MD5>=2.36:security/p5-Digest-MD5 \
		p5-ExtUtils-MakeMaker>=6.4:devel/p5-ExtUtils-MakeMaker \
		p5-HTML-Table>=2.08:www/p5-HTML-Table \
		p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-JSON>=2.07:converters/p5-JSON \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Module-Install>=1.00:devel/p5-Module-Install \
		p5-Module-Pluggable>=3.6:devel/p5-Module-Pluggable \
		p5-Parse-Range>=0.96:math/p5-Parse-Range \
		p5-Regexp-Common>=2.108:textproc/p5-Regexp-Common \
		p5-Regexp-Common-net-CIDR>=0.02:textproc/p5-Regexp-Common-net-CIDR \
		p5-REST-Client>=243:www/p5-REST-Client \
		p5-Snort-Rule>=1.07:security/p5-Snort-Rule \
		p5-Text-Table>=1.114:textproc/p5-Text-Table
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
