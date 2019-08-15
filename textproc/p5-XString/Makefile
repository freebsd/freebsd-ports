# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XString
PORTVERSION=	0.002
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ATOOMIC
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Isolated String helpers from B

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test2-Plugin-NoWarnings>=0:devel/p5-Test2-Plugin-NoWarnings \
		p5-Test2-Suite>=0:devel/p5-Test2-Suite \
		p5-Test2-Tools-Explain>=0:devel/p5-Test2-Tools-Explain

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XString/XString.so

.include <bsd.port.mk>
