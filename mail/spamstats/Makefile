# New ports collection makefile for:	spamstats
# Date created:				14 March 2003
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spamstats
PORTVERSION=	0.4b4
CATEGORIES=	mail
MASTER_SITES=	http://www.gryzor.com/tools/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A tool to generate statistics for spamd of Mail::SpamAssassin

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@${PERL} -pi.bak -e 's,/mail.log,/maillog,g' ${WRKSRC}/${PORTNAME}${PORTVERSION}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}${PORTVERSION}.pl ${PREFIX}/bin/${PORTNAME}.pl
.ifndef	(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in QUICK README copyright
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
