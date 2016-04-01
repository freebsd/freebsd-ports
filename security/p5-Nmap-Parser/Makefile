# Created by: Joshua D. Abraham <jabra@ccs.neu.edu>
# $FreeBSD$

PORTNAME=	Nmap-Parser
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Parse nmap scan data with perl

BUILD_DEPENDS=	p5-XML-Twig>=3.16:textproc/p5-XML-Twig \
		p5-Storable>=2:devel/p5-Storable
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		nmap:security/nmap

USES=		perl5
USE_PERL5=	configure

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
