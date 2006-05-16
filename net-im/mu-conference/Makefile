# New ports collection makefile for:	mu-conference
# Date created:			Mon Feb  9 15:34:59 MSK 2004
# Whom:				Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$

PORTNAME=	mu-conference
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://jabber.terrapin.com/JCR/:jcr
MASTER_SITE_SUBDIR=	distfiles
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jcr-${JCR_VER}.tar.gz:jcr

MAINTAINER=	dsh@vlink.ru
COMMENT=	Multi-User Conferencing component for Jabber

USE_GNOME=	glib20
USE_RC_SUBR=	${PORTNAME}.sh

WRKSRC=		${WRKDIR}/jcr-${JCR_VER}

JCR_VER?=	0.2.4

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${WRKSRC}

post-build:
.for i in jcomp.mk main.c
	${CP} ${WRKSRC}/src/${i} ${WRKSRC}/${DISTNAME}/src/
.endfor
	(cd ${WRKSRC}/${DISTNAME}/src; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} jcomp.mk)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}/src/mu-conference ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}/muc-jcr.xml ${PREFIX}/etc/muc.xml-dist
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in FAQ README
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
