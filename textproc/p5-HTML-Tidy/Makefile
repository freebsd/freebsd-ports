# Created by: mat
# $FreeBSD$

PORTNAME=	HTML-Tidy
PORTVERSION=	1.54
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web validation in a Perl object using tidy

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
LIB_DEPENDS=	tidyp:${PORTSDIR}/textproc/tidyp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::Tidy.3 HTML::Tidy::Message.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile.PL

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README.markdown

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
