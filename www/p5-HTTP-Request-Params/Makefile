# New ports collection makefile for:	p5-HTTP-Request-Params
# Date created:				22 Nov 2005
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	HTTP-Request-Params
PORTVERSION=	1.01
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve GET/POST Parameters from HTTP Requests

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Email/MIME/Modifier.pm:${PORTSDIR}/mail/p5-Email-MIME \
		${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Request::Params.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
