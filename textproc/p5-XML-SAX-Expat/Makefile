PORTNAME=	XML-SAX-Expat
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple API for XML

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-XML-NamespaceSupport>=0:textproc/p5-XML-NamespaceSupport

USES=		perl5 dos2unix
USE_PERL5=	configure

CONFIGURE_ENV=	SKIP_SAX_INSTALL=yes
NO_ARCH=	yes

.include <bsd.port.mk>
