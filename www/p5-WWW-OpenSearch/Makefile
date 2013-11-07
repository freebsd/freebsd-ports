# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	WWW-OpenSearch
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search A9 OpenSearch compatible engines

BUILD_DEPENDS=	p5-URI-Template>=0:${PORTSDIR}/net/p5-URI-Template \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Data-Page>=2.00:${PORTSDIR}/databases/p5-Data-Page \
		p5-XML-Feed>=0.08:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-libwww>=5.60:${PORTSDIR}/www/p5-libwww \
		p5-XML-LibXML>=1.58:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
