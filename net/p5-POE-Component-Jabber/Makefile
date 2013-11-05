# Created by: Jeff Putsch <jdputsch@comcast.net>
# $FreeBSD$

PORTNAME=	POE-Component-Jabber
PORTVERSION=	3.00
PORTREVISION=	1
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE Component for communicating over Jabber

BUILD_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Filter-Template>=0:${PORTSDIR}/devel/p5-Filter-Template \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-POE-Component-PubSub>=0:${PORTSDIR}/net/p5-POE-Component-PubSub \
		p5-POE-Component-SSLify>=0:${PORTSDIR}/security/p5-POE-Component-SSLify \
		p5-POE-Filter-XML>=0:${PORTSDIR}/textproc/p5-POE-Filter-XML \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
CONFIGURE_ARGS=	</dev/null

PORTEXAMPLES=	*

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
