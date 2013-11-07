# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-TreePP
PORTVERSION=	0.41
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl implementation for parsing/writing xml files

USES=		perl5
USE_PERL5=	configure

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example/envxml.cgi ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
