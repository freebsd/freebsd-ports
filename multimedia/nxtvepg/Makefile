# New ports collection makefile for:	nxtvepg-2.4.2
# Date created:		07 Jan 2003
# Whom:			Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	nxtvepg
PORTVERSION=	2.7.1
CATEGORIES=	multimedia tcl84 tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	barner@gmx.de
COMMENT=	Viewer for Nextview Electronic TV Programme Guide (needs bktr driver)

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

USE_GMAKE=	yes
USE_XLIB=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} WRKSRC=${WRKSRC}

MAN1=		nxtvepg.1
MYPORTDOCS=	README TODO CHANGES manual.html

.include <bsd.port.pre.mk>

pre-everything::
.if ${OSVERSION} < 500000
ONLY_FOR_ARCHS=	i386
.else
ONLY_FOR_ARCHS=	alpha i386
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nxtvepg ${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/Nxtvepg.ad ${PREFIX}/lib/X11/app-defaults/Nxtvepg
	${INSTALL_MAN}     ${WRKSRC}/nxtvepg.1 ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
