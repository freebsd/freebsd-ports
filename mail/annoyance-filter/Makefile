# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	annoyance-filter
PORTVERSION=	1.0d
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	SF/annoyancefilter/annoyancefilter/${PORTVERSION} \
		http://www.fourmilab.ch/annoyance-filter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptive Bayesian Junk Mail Filter

LICENSE=	PD GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_PD=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GNU

USE_GCC=	yes
GNU_CONFIGURE=	yes

# The port does not build with C++11 or later (GCC 6 defaults to -std=gnu++14).
USE_CXXSTD=	gnu++03

PORTDOCS=	INSTALL README *.pdf

PLIST_FILES=	bin/annoyance-filter \
		bin/annoyance-filter-run \
		man/man1/annoyance-filter.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-run ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
