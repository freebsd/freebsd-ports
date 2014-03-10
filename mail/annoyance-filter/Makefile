# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	annoyance-filter
PORTVERSION=	1.0d
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/annoyancefilter/annoyancefilter/${PORTVERSION} \
		http://www.fourmilab.ch/annoyance-filter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptive Bayesian Junk Mail Filter

USE_GCC=	yes
GNU_CONFIGURE=	yes

DOCS=		COPYING INSTALL README *.pdf

CFLAGS=		${CPPFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-run ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
