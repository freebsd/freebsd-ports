# New ports collection makefile for:	newsgrab
# Date Created:				11 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	newsgrab
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	newsgrab
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Download and uudecode binary files from USENET using regexps

RUN_DEPENDS=	${SITE_PERL}/News/NNTPClient.pm:${PORTSDIR}/news/p5-NNTPClient \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/News/Newsrc.pm:${PORTSDIR}/news/p5-News-Newsrc \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|' ${WRKSRC}/newsgrab.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/newsgrab.pl ${PREFIX}/bin/newsgrab
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/newsgrab
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/newsgrab
	${INSTALL_DATA} ${WRKSRC}/newsgrabrc ${PREFIX}/share/doc/newsgrab
.endif

.include <bsd.port.mk>
