PORTNAME=	POE-Component-Client-Traceroute
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Non-blocking traceroute client

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-POE>=0.11:devel/p5-POE

USES=		perl5 shebangfix
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*
SHEBANG_FILES=	examples/poe-traceroute.pl

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
