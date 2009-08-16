# New ports collection makefile for:	p5-PHP-Session
# Date created:				16 April 2003
# Whom:	      				Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	PHP-Session
PORTVERSION=	0.27
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read / write PHP session files

RUN_DEPENDS=	p5-UNIVERSAL-require>=0.03:${PORTSDIR}/devel/p5-UNIVERSAL-require

PERL_CONFIGURE=	yes

MAN3=		PHP::Session.3 PHP::Session::Serializer::PHP.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
