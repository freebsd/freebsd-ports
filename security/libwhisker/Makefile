# New ports collection makefile for: 	libwhisker
# Date created: 			20 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#

PORTNAME=	libwhisker
PORTVERSION= 	1.6
PORTREVISION=	1
CATEGORIES= 	security perl5

MAINTAINER= 	jan@atstake.com
COMMENT=	Perl module to create HTTP test scripts

MASTER_SITES=	http://www.wiretrip.net/rfp/${PORTNAME}/
DISTNAME=	${PORTNAME}-current

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
	@${MKDIR} ${PREFIX}/share/doc/libwhisker \
		&& ${CHMOD} 755 ${PREFIX}/share/doc/libwhisker
	@${MKDIR} ${PREFIX}/share/doc/libwhisker/docs \
		&& ${CHMOD} 755 ${PREFIX}/share/doc/libwhisker/docs
	@${MKDIR} ${PREFIX}/share/doc/libwhisker/imgs \
		&& ${CHMOD} 755 ${PREFIX}/share/doc/libwhisker/imgs
	@${MKDIR} ${PREFIX}/share/doc/libwhisker/scripts \
		&& ${CHMOD} 755 ${PREFIX}/share/doc/libwhisker/scripts
.for i in ${DOC1}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/libwhisker/
.endfor
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/libwhisker/docs/
.endfor
.for i in ${IMGS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/libwhisker/imgs/
.endfor
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/share/doc/libwhisker/scripts/
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/api_demo.pl ${PREFIX}/share/doc/libwhisker/
	${INSTALL_SCRIPT} ${WRKSRC}/simple.pl ${PREFIX}/share/doc/libwhisker/
.endif

.include <bsd.port.mk>
