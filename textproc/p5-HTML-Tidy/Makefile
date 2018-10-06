# Created by: mat
# $FreeBSD$

PORTNAME=	HTML-Tidy
PORTVERSION=	1.60
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web validation in a Perl object using tidy

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww
LIB_DEPENDS=	libtidyp.so:textproc/tidyp

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README.markdown

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/HTML/Tidy/Tidy.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
