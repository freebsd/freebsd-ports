# New ports collection makefile for:	p5-Apache-Clean
# Date created:				Sep 09 2003
# Whom:	      				Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-Clean
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Apache/GEOFF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A mod_perl interface into HTML::Clean

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/HTML/Clean.pm:${PORTSDIR}/www/p5-HTML-Clean

PORTSCOUT=	limit:^0

PERL_CONFIGURE=	yes

MAN3=		Apache::Clean.3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
