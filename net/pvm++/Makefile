# ex:ts=8
# New ports collection makefile for:   pvm++
# Date created:                Jan 29, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pvm++
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://pvm-plus-plus.sourceforge.net/pub/%SUBDIR%/ \
		http://goethe.ira.uka.de/~wilhelmi/pvm++/
MASTER_SITE_SUBDIR=	${PORTNAME:S:+:-plus:g}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libpvm3.a:${PORTSDIR}/net/pvm

USE_GMAKE=	yes
USE_LIBTOOL=	yes
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
