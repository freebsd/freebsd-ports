# ex:ts=8
# New ports collection makefile for:   pvm++
# Date created:                Jan 29, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pvm++
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	net parallel
MASTER_SITES=	SF/pvm-plus-plus/pvm-plus-plus/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++-Library for PVM

BUILD_DEPENDS=	${LOCALBASE}/lib/libpvm3.a:${PORTSDIR}/net/pvm

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pvm-incs=${LOCALBASE}/include \
		--with-pvm-libs=${LOCALBASE}/lib
USE_LDCONFIG=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
