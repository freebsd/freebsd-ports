PORTNAME=	XML-LibXSLT
PORTVERSION=	2.003000
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the GNOME XSLT library
WWW=		https://metacpan.org/release/XML-LibXSLT

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-LibXML>=1.70:textproc/p5-XML-LibXML

USES=		gnome perl5 pkgconfig
USE_GNOME=	libxml2 libxslt
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XML/LibXSLT/LibXSLT.so

.include <bsd.port.mk>
