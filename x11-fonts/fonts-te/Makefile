# New ports collection makefile for:	fonts-te
# Date created:		Jan 24 2007
# Whom:			Prudhvi Krishna <prudhvikrishna@gmail.com>
#
# $FreeBSD$

PORTNAME=	fonts-te
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://itachi.prudhvi.org/te_fonts/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
COMMENT=	Telugu fonts for te_IN.

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
NO_BUILD=	yes
PORTDOCS=	MANUAL.PDF
PKGMESSAGE=	${PKGDIR}/pkg-message
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTSDIR=${FONTSDIR:S|^${PREFIX}/||}

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Pothana2000.ttf ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/vemana.ttf ${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
