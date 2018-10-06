# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-EPP
PORTVERSION=	0.22
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client library for the TCP transport for EPP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Digest-SHA1>=2.12:security/p5-Digest-SHA1 \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
