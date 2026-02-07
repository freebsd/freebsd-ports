PORTNAME=	Net-SSH2
PORTVERSION=	0.74
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Support for the SSH 2 protocol via libSSH2
WWW=		https://metacpan.org/release/Net-SSH2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		compiler:c11 localbase perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${STAGEDIR}${EXAMPLESDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/SSH2/SSH2.so

.include <bsd.port.mk>
