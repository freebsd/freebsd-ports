# Created by: Jeff Putsch <jdputsch@comcast.net>
# $FreeBSD$

PORTNAME=	POE-Component-Jabber
PORTVERSION=	3.00
PORTREVISION=	3
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE Component for communicating over Jabber

BUILD_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Filter-Template>=0:devel/p5-Filter-Template \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-POE-Component-PubSub>=0:net/p5-POE-Component-PubSub \
		p5-POE-Component-SSLify>=0:security/p5-POE-Component-SSLify \
		p5-POE-Filter-XML>=0:textproc/p5-POE-Filter-XML \
		p5-POE>=0:devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	examples/*
USE_PERL5=	modbuild
CONFIGURE_ARGS=	</dev/null
NO_ARCH=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
