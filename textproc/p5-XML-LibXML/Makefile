PORTNAME=	XML-LibXML
PORTVERSION=	2.0210
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to Gnome libxml2 library
WWW=		https://metacpan.org/release/XML-LibXML

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-NamespaceSupport>=1.07:textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX>=0.11:textproc/p5-XML-SAX
TEST_DEPENDS=	p5-Test-LeakTrace>=0:devel/p5-Test-LeakTrace \
		p5-URI>=0:net/p5-URI

USES=		gnome perl5
USE_GNOME=	libxml2
USE_PERL5=	configure

CONFIGURE_ENV=	LOCALBASE=${LOCALBASE} SKIP_SAX_INSTALL=1
PKGDEINSTALL=	${PKGINSTALL}

CONFLICTS_INSTALL=	p5-XML-LibXML-XPathContext p5-XML-LibXML-Common

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XML/LibXML/LibXML.so

.include <bsd.port.mk>
