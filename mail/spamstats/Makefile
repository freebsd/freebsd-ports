# New ports collection makefile for:	spamstats
# Date created:				14 March 2003
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spamstats
PORTVERSION=	0.6c
PORTREVISION=	2
CATEGORIES=	mail
#MASTER_SITES=	http://www.inl.fr/download/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	leeym

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A tool to generate statistics for spamd of Mail::SpamAssassin

RUN_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Compress-Bzip2>=2.08:${PORTSDIR}/archivers/p5-Compress-Bzip2

USE_PERL5=	yes
NO_BUILD=	yes
PORTDOCS=	QUICK README copyright
PLIST_FILES=	bin/spamstats.pl

post-patch:
	@${PERL} -pi.bak -e 's,/mail.log,/maillog,g' ${WRKSRC}/${PORTNAME}${PORTVERSION}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}${PORTVERSION}.pl ${PREFIX}/bin/${PORTNAME}.pl
.ifndef	(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
