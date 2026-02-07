PORTNAME=	HTML-Chunks
PORTVERSION=	1.55.1
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple nested template engine for HTML, XML and XHTML
WWW=		https://metacpan.org/release/HTML-Chunks

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Stringy>=0:devel/p5-IO-Stringy

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
