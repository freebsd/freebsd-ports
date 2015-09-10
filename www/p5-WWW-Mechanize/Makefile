# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize
PORTVERSION=	1.75
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This module is to help you automate interaction with a website

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI>=4.08:${PORTSDIR}/www/p5-CGI \
		p5-HTML-Form>=6:${PORTSDIR}/www/p5-HTML-Form \
		p5-HTML-Parser>=3.33:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTTP-Server-Simple>=0.35:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.829:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Taint>=0:${PORTSDIR}/devel/p5-Test-Taint \
		p5-Test-Warn>=0.11:${PORTSDIR}/devel/p5-Test-Warn

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

DOCS=		Changes etc/www-mechanize-logo.png
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
