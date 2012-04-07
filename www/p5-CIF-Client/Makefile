# New ports collection makefile for:    p5-CIF-Client
# Date created:                         Mar 27 2012
# Whom:                                 pauls@utdallas.edu
#
# $FreeBSD$
#

PORTNAME=	CIF-Client
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAXJAZMAN/cif
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Extends REST::Client for use with the CI-Framework REST interface

BUILD_DEPENDS=	p5-REST-Client>=0:${PORTSDIR}/www/p5-REST-Client \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install \
		p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table \
		p5-HTML-Table>=0:${PORTSDIR}/www/p5-HTML-Table \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
		p5-Config-Simple>=0:${PORTSDIR}/devel/p5-Config-Simple \
		p5-Snort-Rule>=0:${PORTSDIR}/security/p5-Snort-Rule \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Regexp-Common-net-CIDR>=0:${PORTSDIR}/textproc/p5-Regexp-Common-net-CIDR \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=	CIF::Client.3

.include <bsd.port.mk>
