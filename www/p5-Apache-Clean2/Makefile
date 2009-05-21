# New ports collection makefile for:	p5-Apache-Clean
# Date created:				Sep 09 2003
# Whom:	      				Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Clean
PORTVERSION=	2.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Apache/GEOFF
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}_7

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A mod_perl interface into HTML::Clean

BUILD_DEPENDS=	mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-HTML-Clean>=0.8:${PORTSDIR}/www/p5-HTML-Clean

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}2

PERL_CONFIGURE=	yes

MAN3=		Apache::Clean.3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
