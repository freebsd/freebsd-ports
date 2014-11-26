# Created by: pandzilla
# $FreeBSD$

PORTNAME=	libwhisker
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	SF/whisker/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	se@FreeBSD.org
COMMENT=	Perl module to create HTTP test scripts

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
USES=		perl5
PLIST_FILES=	%%SITE_PERL%%/LW2.pm \
		%%PERL5_MAN3%%/LW2.3pm.gz

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/man/man3
	cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${PERL5} Makefile.pl install
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/scripts
	cd ${WRKSRC} && ${INSTALL_DATA} README CHANGES KNOWNBUGS ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/docs
	cd ${WRKSRC}/scripts/ && ${INSTALL_SCRIPT} * ${STAGEDIR}${DOCSDIR}/scripts

.include <bsd.port.mk>
