# New ports collection makefile for:   dvdauthor
# Date created:        20 April 2003
# Whom:                pb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dvdauthor
PORTVERSION=	0.6.9
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pb@FreeBSD.org
COMMENT=	Makes a DVD file structure from one or more MPEG2 streams

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		png.5:${PORTSDIR}/graphics/png \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS="-L${LOCALBASE}/lib"
MAN1=	dvdauthor.1 spumux.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${WRKSRC}/lib.txt ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${WRKSRC}/menu.txt ${PREFIX}/share/doc/dvdauthor
	for i in dvdauthor ex-title examples index languages manpages spumux; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$i.html ${PREFIX}/share/doc/dvdauthor; \
	done
.endif

.include <bsd.port.mk>
