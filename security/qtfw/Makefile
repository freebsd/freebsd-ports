# New ports collection makefile for:	qtfw
# Date created:				Sat Aug 25 10:42:02 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	qtfw
PORTVERSION=	0.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	2
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS}" X11BASE="${X11BASE}"

pre-patch:
	@${PERL} -pi.orig -e 's|^\ *CXXFLAGS=.*||' \
		${WRKSRC}/configure
	@${PERL} -pi.orig -e 's|\-O2||' ${WRKSRC}/qtfw/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qtfw/qtfw ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for files in gear qtfwlogo
	@${INSTALL_DATA} ${WRKSRC}/pics/${files}.png ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in index.html ipfwman.html qtfwlogo.jpeg
	@${INSTALL_DATA} ${WRKSRC}/docs/${docs} ${DOCSDIR}
.endfor
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/examples/* \
		${PREFIX}/share/examples/${PORTNAME}
.endif

.include <bsd.port.mk>
