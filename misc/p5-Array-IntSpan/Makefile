# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Array-IntSpan
PORTVERSION=	2.002
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for handling arrays using IntSpan techniques

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' -e 's/3pm/3/g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
