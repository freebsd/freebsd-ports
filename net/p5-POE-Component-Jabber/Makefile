# ex:ts=8
# New ports collection makefile for:	POE::Component::Jabber
# Date created:		6 Aug 2004
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Jabber
PORTVERSION=	1.0
CATEGORIES=	net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:1,2/}
MASTER_SITE_SUBDIR=	POE/:1 ExtUtils/:2
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1 \
		ExtUtils-AutoInstall-0.59${EXTRACT_SUFX}:2

MAINTAINER=	jdputsch@comcast.net
COMMENT=	A POE Component for communicating over Jabber

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Filter/XML.pm:${PORTSDIR}/textproc/p5-POE-Filter-XML \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Jabber.3 \
		POE::Component::Jabber::Client::Component.3 \
		POE::Component::Jabber::Client::J2.3 \
		POE::Component::Jabber::Client::Legacy.3 \
		POE::Component::Jabber::Client::XMPP.3 \
		POE::Component::Jabber::Client::XMPP::TLS.3 \
		POE::Component::Jabber::Error.3 \
		POE::Component::Jabber::Server::Socket::CTLS.3 \
		POE::Component::Jabber::Server::Socket::STLS.3

pre-configure:
	@${ECHO_MSG} "===>   Putting AutoInstall.pm in work dir"
	@${MKDIR} ${WRKSRC}/install/ExtUtils
	@${CP} ${WRKDIR}/ExtUtils-AutoInstall-0.59/lib/ExtUtils/AutoInstall.pm \
	 ${WRKSRC}/install/ExtUtils

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' \
		${WRKSRC}/lib/POE/Component/Jabber/Client/Legacy.pm \
		${WRKSRC}/lib/POE/Component/Jabber/Client/Component.pm \
		${WRKSRC}/lib/POE/Component/Jabber/Client/XMPP.pm \
		${WRKSRC}/lib/POE/Component/Jabber/Client/J2.pm \
		${WRKSRC}/lib/POE/Component/Jabber/Error.pm \
		${WRKSRC}/lib/POE/Component/Jabber.pm
.endif

.include <bsd.port.post.mk>
