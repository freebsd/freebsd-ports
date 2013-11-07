# Created by: Eric A. Griff <eric@talesfromthereal.com>
# $FreeBSD$

PORTNAME=	WDDX
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PETDANCE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to parse WDDX Packets

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
