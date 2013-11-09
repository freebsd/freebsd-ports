# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-TreePP
PORTVERSION=	0.42
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl implementation for parsing/writing xml files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-libwww>=5.811:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-HTTP-Lite>=0:${PORTSDIR}/www/p5-HTTP-Lite \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	example/envxml.cgi

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example/envxml.cgi ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
