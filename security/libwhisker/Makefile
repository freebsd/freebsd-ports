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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to create HTTP test scripts

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	${SITE_PERL_REL}/LW.pm

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.pl lib

do-install:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.pl ${INSTALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/docs ${DOCSDIR}/imgs ${DOCSDIR}/scripts
	cd ${WRKSRC} && ${INSTALL_DATA} README CHANGES KNOWNBUGS ${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} * ${DOCSDIR}/docs
	cd ${WRKSRC}/imgs/ && ${INSTALL_DATA} * ${DOCSDIR}/imgs
	cd ${WRKSRC}/scripts/ && ${INSTALL_SCRIPT} * ${DOCSDIR}/scripts
.endif

.include <bsd.port.mk>
