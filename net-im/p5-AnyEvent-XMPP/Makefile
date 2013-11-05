# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-XMPP
PORTVERSION=	0.54
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implementation of the XMPP Protocol

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-Object-Event>=0.7:${PORTSDIR}/devel/p5-Object-Event
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>
# One of it's dependency is p5-GSSAPI which is marked broken for 7.X
.if ${OSVERSION} < 800000
BROKEN=	Does not work on FreeBSD 7.x
.endif

.include <bsd.port.post.mk>
