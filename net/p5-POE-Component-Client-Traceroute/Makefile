# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	POE-Component-Client-Traceroute
PORTVERSION=	0.21
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A non-blocking traceroute client

RUN_DEPENDS=	p5-POE>=0.11:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*
SHEBANG_FILES=	examples/poe-traceroute.pl

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
