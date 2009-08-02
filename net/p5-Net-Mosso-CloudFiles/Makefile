# New ports collection makefile for:	p5-Net-Mosso-CloudFiles
# Date created:		2008-10-23
# Whom:			glarkin
#
# $FreeBSD$
#

PORTNAME=	Net-Mosso-CloudFiles
PORTVERSION=	0.43
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Perl interface to the Mosso CloudFiles service

RUN_DEPENDS=	p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-MD5-File>=0:${PORTSDIR}/security/p5-Digest-MD5-File \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-LWP-UserAgent-Determined>=0:${PORTSDIR}/www/p5-LWP-UserAgent-Determined \
		p5-Data-Stream-Bulk>=0:${PORTSDIR}/devel/p5-Data-Stream-Bulk \
		p5-LWP-ConnCache-MaxKeepAliveRequests>=0:${PORTSDIR}/www/p5-LWP-ConnCache-MaxKeepAliveRequests \
		p5-JSON-XS-VersionOneAndTwo>=0:${PORTSDIR}/converters/p5-JSON-XS-VersionOneAndTwo \
		p5-DateTime-Format-HTTP>=0:${PORTSDIR}/devel/p5-DateTime-Format-HTTP \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Mosso::CloudFiles.3 \
		Net::Mosso::CloudFiles::Container.3 \
		Net::Mosso::CloudFiles::Object.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
