# ex:ts=8
# New ports collection makefile for:	POE::Component::Jabber
# Date created:		6 Aug 2004
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Jabber
PORTVERSION=	2.03
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE Component for communicating over Jabber

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Filter-Template>=0:${PORTSDIR}/devel/p5-Filter-Template \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Filter-XML>=0:${PORTSDIR}/textproc/p5-POE-Filter-XML

PERL_MODBUILD=	5.8.8+	# required by vendor
CONFIGURE_ARGS=	</dev/null

PORTEXAMPLES=	*
MAN3=		POE::Component::Jabber.3 \
		POE::Component::Jabber::Error.3 \
		POE::Component::Jabber::J14.3 \
		POE::Component::Jabber::J2.3 \
		POE::Component::Jabber::Legacy.3 \
		POE::Component::Jabber::Protocol.3 \
		POE::Component::Jabber::ProtocolFactory.3 \
		POE::Component::Jabber::Status.3 \
		POE::Component::Jabber::Utility::ClientHandle.3 \
		POE::Component::Jabber::Utility::SSLify.3 \
		POE::Component::Jabber::Utility::ServerHandle.3 \
		POE::Component::Jabber::XMPP.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
