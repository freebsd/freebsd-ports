# New ports collection makefile for:	newsgrab
# Date Created:				11 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	newsgrab
PORTVERSION=	0.3.1
CATEGORIES=	news
MASTER_SITES=	http://telia.dl.sourceforge.net/sourceforge/newsgrab/ \
		${MASTER_SITE_SOURCEFORGE}

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/News/NNTPClient.pm:${PORTSDIR}/news/p5-NNTPClient \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/News/Newsrc.pm:${PORTSDIR}/news/p5-News-Newsrc \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

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
