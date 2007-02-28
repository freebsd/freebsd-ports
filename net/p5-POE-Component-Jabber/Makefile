# ex:ts=8
# New ports collection makefile for:	POE::Component::Jabber
# Date created:		6 Aug 2004
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Jabber
PORTVERSION=	1.21
CATEGORIES=	net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
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

PERL_MODBUILD=	yes

MAN3=		POE::Component::Jabber.3 \
		POE::Component::Jabber::Client::Component.3 \
		POE::Component::Jabber::Client::J2.3 \
		POE::Component::Jabber::Client::Legacy.3 \
		POE::Component::Jabber::Client::XMPP.3 \
		POE::Component::Jabber::Error.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801 # required by vendor
IGNORE=	requires at least Perl 5.8.1.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
