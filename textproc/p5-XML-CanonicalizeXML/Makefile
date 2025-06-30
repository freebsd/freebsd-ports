PORTNAME=	XML-CanonicalizeXML
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extension for inclusive/exclusive canonicalization of XML
WWW=		https://metacpan.org/release/XML-CanonicalizeXML

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		gnome perl5
USE_GNOME=	libxml2
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XML/CanonicalizeXML/CanonicalizeXML.so

.include <bsd.port.mk>
