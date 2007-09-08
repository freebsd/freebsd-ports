# ex:ts=8
# New ports collection makefile for:	POE::Component::Jabber
# Date created:		6 Aug 2004
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Jabber
PORTVERSION=	2.02
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE Component for communicating over Jabber

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/Filter/Template.pm:${PORTSDIR}/devel/p5-Filter-Template \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL \
		${SITE_PERL}/POE/Component/SSLify.pm:${PORTSDIR}/security/p5-POE-Component-SSLify \
		${SITE_PERL}/POE/Filter/XML.pm:${PORTSDIR}/textproc/p5-POE-Filter-XML \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.8+	# required by vendor
CONFIGURE_ARGS=	</dev/null

MAN3=		POE::Component::Jabber.3 POE::Component::Jabber::Error.3 \
		POE::Component::Jabber::J14.3 POE::Component::Jabber::J2.3 \
		POE::Component::Jabber::Legacy.3 \
		POE::Component::Jabber::Protocol.3 \
		POE::Component::Jabber::ProtocolFactory.3 \
		POE::Component::Jabber::Status.3 POE::Component::Jabber::XMPP.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
