# New ports collection makefile for:    gnut
# Date created:         19 April 2000
# Whom:                 kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnut
PORTVERSION=	0.4.28
CATEGORIES=	net audio
MASTER_SITES=	http://www.gnutelliums.com/linux_unix/gnut/tars/

MAINTAINER=	kris@FreeBSD.org

FORBIDDEN=	"The distfile appears to have been withdrawn due to a vulnerability allowing injection of HTML code into the web front-end: http://www.der-keiler.de/Mailing-Lists/Securiteam/2001-09/0021.html"

USE_AUTOCONF=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnut ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gnut
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gnut
.for file in TUTORIAL gnut-1.html gnut-2.html gnut-3.html gnut-4.html gnut-5.html gnut-6.html gnut.html
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/gnut
.endfor
.endif
	${MKDIR} ${PREFIX}/share/gnut
	${INSTALL_DATA} ${WRKSRC}/gnutrc.sample ${PREFIX}/share/gnut

.include <bsd.port.mk>
