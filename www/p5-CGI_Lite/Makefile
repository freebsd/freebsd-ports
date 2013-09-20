# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Lite
PORTVERSION=	2.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Process and decode WWW forms and cookies

USES=		perl5
USE_PERL5=	configure

MAN3=		CGI::Lite.3

DOCS=		CHANGES README TODO
EXAMPLES=	cookies get_post print upload file post reference

NO_STAGE=	yes
post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing docs for ${PKGNAME}"
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_SCRIPT} ${EXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
