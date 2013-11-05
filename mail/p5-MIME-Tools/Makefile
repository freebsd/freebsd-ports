# Created by: Eivind Eklund <eivind@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MIME-Tools
PORTVERSION=	5.504
PORTEPOCH=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DSKOLL
PKGNAMEPREFIX=	p5-
DISTNAME=	MIME-tools-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set of perl5 modules for MIME

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Convert-BinHex>=0:${PORTSDIR}/converters/p5-Convert-BinHex \
		p5-IO-stringy>=2.11:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Mail-Tools>=1.0203:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
