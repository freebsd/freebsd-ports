# New ports collection makefile for:	annoyance-filter
# Date created:		2004-01-02
# Whom:			Sergei Kolobov <sergei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	annoyance-filter
PORTVERSION=	1.0d
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.fourmilab.ch/annoyance-filter/
MASTER_SITE_SUBDIR=	${PORTNAME:S/-//}

MAINTAINER=	barner@gmx.de
COMMENT=	Adaptive Bayesian Junk Mail Filter

#USE_GPG=		yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=		yes
CFLAGS+=		${CPPFLAGS}

MAN1=		annoyance-filter.1
DOCS=		COPYING INSTALL README *.pdf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-run ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
