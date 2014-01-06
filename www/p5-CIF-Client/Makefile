# Created by: pauls@utdallas.edu
# $FreeBSD$

PORTNAME=	CIF-Client
PORTVERSION=	0.21
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAXJAZMAN/cif
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Extends REST::Client for use with the CI-Framework REST interface

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.31:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Compress-Raw-Zlib>=2.008:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib \
		p5-Config-Simple>=4.58:${PORTSDIR}/devel/p5-Config-Simple \
		p5-Digest-SHA1>=2.11:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Digest-MD5>=2.36:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-ExtUtils-MakeMaker>=6.4:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-HTML-Table>=2.08:${PORTSDIR}/www/p5-HTML-Table \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-JSON>=2.07:${PORTSDIR}/converters/p5-JSON \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-Module-Install>=1.00:${PORTSDIR}/devel/p5-Module-Install \
		p5-Module-Pluggable>=3.6:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Parse-Range>=0.96:${PORTSDIR}/math/p5-Parse-Range \
		p5-Regexp-Common>=2.108:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Regexp-Common-net-CIDR>=0.02:${PORTSDIR}/textproc/p5-Regexp-Common-net-CIDR \
		p5-REST-Client>=243:${PORTSDIR}/www/p5-REST-Client \
		p5-Snort-Rule>=1.07:${PORTSDIR}/security/p5-Snort-Rule \
		p5-Text-Table>=1.114:${PORTSDIR}/textproc/p5-Text-Table
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
