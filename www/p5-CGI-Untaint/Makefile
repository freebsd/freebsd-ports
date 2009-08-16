# New ports collection makefile for:	p5-CGI-Untaint
# Date created:	   21 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	CGI-Untaint
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Process CGI input parameters

RUN_DEPENDS=	p5-UNIVERSAL-require>=0.01:${PORTSDIR}/devel/p5-UNIVERSAL-require

PERL_CONFIGURE=	yes

MAN3=		CGI::Untaint.3 CGI::Untaint::hex.3 CGI::Untaint::integer.3 \
       		CGI::Untaint::object.3 CGI::Untaint::printable.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
