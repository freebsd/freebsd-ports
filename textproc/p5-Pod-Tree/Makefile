# Created by: ijliao
# $FreeBSD$

PORTNAME=	Pod-Tree
PORTVERSION=	1.17
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create a static syntax tree for a POD

RUN_DEPENDS=	p5-HTML-Stream>=1.49:${PORTSDIR}/www/p5-HTML-Stream \
		p5-IO-String>=1:${PORTSDIR}/devel/p5-IO-String \
		p5-Text-Template>=1:${PORTSDIR}/textproc/p5-Text-Template
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

# conflict with pod2html in perl 5.6 or above
post-patch:
	${REINPLACE_CMD} -e 's/pod2html //g' ${WRKSRC}/Makefile.PL
	${REINPLACE_CMD} -e '/pod2html/d' ${WRKSRC}/MANIFEST
	${RM} ${WRKSRC}/t/pod2html.t

.include <bsd.port.mk>
