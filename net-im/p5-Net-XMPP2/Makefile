# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-XMPP2
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Implementation of the XMPP Protocol

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-BS-Event>=0:${PORTSDIR}/devel/p5-BS-Event \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Object-Event>=0:${PORTSDIR}/devel/p5-Object-Event \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer
RUN_DEPENDS:=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-BS-Event>=0:${PORTSDIR}/devel/p5-BS-Event \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Object-Event>=0:${PORTSDIR}/devel/p5-Object-Event \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
