# Created by: Andrew <andrew@ugh.net.au>
# $FreeBSD$

PORTNAME=	XML-Simple
PORTVERSION=	2.20
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Trivial API for reading and writing XML (esp config files)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-SAX>=0.15:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-SAX-Expat>=0:${PORTSDIR}/textproc/p5-XML-SAX-Expat
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
