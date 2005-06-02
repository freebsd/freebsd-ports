# ex:ts=8
# New ports collection makefile for:   pvm++
# Date created:                Jan 29, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pvm++
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	net parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://goethe.ira.uka.de/~wilhelmi/pvm++/
MASTER_SITE_SUBDIR=	${PORTNAME:S:+:-plus:g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++-Library for PVM

BUILD_DEPENDS=	${LOCALBASE}/lib/libpvm3.a:${PORTSDIR}/net/pvm

USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-pvm-incs=${LOCALBASE}/include \
		--with-pvm-libs=${LOCALBASE}/lib
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
