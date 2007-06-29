# New ports collection makefile for: 	libwhisker
# Date created: 			20 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#

PORTNAME=	libwhisker
PORTVERSION=	2.1
CATEGORIES=	security perl5
MASTER_SITES=	http://www.wiretrip.net/rfp/${PORTNAME}/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Perl module to create HTTP test scripts

WRKSRC=		${WRKDIR}/${PORTNAME}2-${PORTVERSION}

NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	${SITE_PERL_REL}/LW.pm \
		${SITE_PERL_REL}/LW2.pm

MAN3=		LW2.3pm
MANPREFIX=	${LOCALBASE}/lib/perl5/${PERL_VERSION}/perl/

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.pl lib

do-install:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.pl ${INSTALL_TARGET}
	@${INSTALL_DATA} ${WRKSRC}/compat/LW.pm ${SITE_PERL}
	@${CHMOD} 444 ${SITE_PERL}/LW2.pm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/docs ${DOCSDIR}/scripts
	cd ${WRKSRC} && ${INSTALL_DATA} README CHANGES KNOWNBUGS ${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} * ${DOCSDIR}/docs
	cd ${WRKSRC}/scripts/ && ${INSTALL_SCRIPT} * ${DOCSDIR}/scripts
.endif

.include <bsd.port.mk>
