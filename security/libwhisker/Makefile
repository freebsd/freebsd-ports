# New ports collection makefile for: 	libwhisker
# Date created: 			20 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#

PORTNAME=	libwhisker
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	http://www.wiretrip.net/rfp/${PORTNAME}/
DISTNAME=	${PORTNAME}-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to create HTTP test scripts

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes
USE_PERL5=	yes

DOC1=		README CHANGES KNOWNBUGS
DOCS=		docs/OPTIMIZE docs/evil.htm docs/whisker_hash.txt
IMGS=		imgs/logo-builton.gif imgs/logo-name.gif imgs/logo-plain.gif
SCRIPTS=	scripts/func2html.pl scripts/prox.pl

do-install:
	@cd ${WRKSRC} && ${PERL} ${WRKSRC}/Makefile.pl lib
	@${MKDIR} ${SITE_PERL}/${PORTNAME} && ${CHMOD} 755 ${SITE_PERL}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/LW.pm ${SITE_PERL}/${PORTNAME}/LW.pm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} \
		&& ${CHMOD} 755 ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/docs \
		&& ${CHMOD} 755 ${DOCSDIR}/docs
	@${MKDIR} ${DOCSDIR}/imgs \
		&& ${CHMOD} 755 ${DOCSDIR}/imgs
	@${MKDIR} ${DOCSDIR}/scripts \
		&& ${CHMOD} 755 ${DOCSDIR}/scripts
.for i in ${DOC1}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/docs/
.endfor
.for i in ${IMGS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/imgs/
.endfor
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DOCSDIR}/scripts/
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/api_demo.pl ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/simple.pl ${DOCSDIR}
.endif

.include <bsd.port.mk>
