# New ports collection makefile for:	newsgrab
# Date Created:				11 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	newsgrab
PORTVERSION=	0.1.5
CATEGORIES=	news
MASTER_SITES=	http://phunkbros.dk/newsgrab/

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/News/NNTPClient.pm:${PORTSDIR}/news/p5-NNTPClient \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@${PERL} -pi -e 's,^#!/usr/bin/perl,#!${PERL},' ${WRKSRC}/newsgrab.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/newsgrab.pl ${PREFIX}/bin/newsgrab
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/newsgrab
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/newsgrab
.endif

.include <bsd.port.mk>
