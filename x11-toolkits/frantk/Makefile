# New ports collection makefile for:   frantk
# Date created:        25 May 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	frantk
PORTVERSION=	1.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.dcs.gla.ac.uk/~meurig/FranTk/
DISTNAME=	FranTk${PORTVERSION:S/./_/}

MAINTAINER=	obraun@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/FranTk1.1/src

ALL_TARGET=	hugs
INSTALL_TARGET=	install_hugs

post-patch:
	${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/frantk.conf

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKDIR}/FranTk1.1/doc/frantk.pdf ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
