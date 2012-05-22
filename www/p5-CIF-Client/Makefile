# New ports collection makefile for:    p5-CIF-Client
# Date created:                         Mar 27 2012
# Whom:                                 pauls@utdallas.edu
#
# $FreeBSD$
#

PORTNAME=	CIF-Client
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAXJAZMAN/cif
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Extends REST::Client for use with the CI-Framework REST interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.31:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Config-Simple>=4.58:${PORTSDIR}/devel/p5-Config-Simple \
		p5-Digest-SHA1>=2.11:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-HTML-Table>=2.08:${PORTSDIR}/www/p5-HTML-Table \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-JSON>=2.07:${PORTSDIR}/converters/p5-JSON \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-Module-Install>=1.00:${PORTSDIR}/devel/p5-Module-Install \
		p5-REST-Client>=243:${PORTSDIR}/www/p5-REST-Client \
		p5-Regexp-Common>=2.108:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Regexp-Common-net-CIDR>=0.02:${PORTSDIR}/textproc/p5-Regexp-Common-net-CIDR \
		p5-Snort-Rule>=1.07:${PORTSDIR}/security/p5-Snort-Rule \
		p5-Text-Table>=1.114:${PORTSDIR}/textproc/p5-Text-Table
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CIF::Client.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-IO-Compress>=2.008:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS+=	p5-IO-Compress>=2.008:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
