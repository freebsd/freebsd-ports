# ex:ts=8
# Ports collection Makefile for:	euler
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	euler
PORTVERSION=	1.60.6
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program computes with real and complex numbers and matrices

WRKSRC=		${WRKDIR}/${DISTNAME:R}/source

USE_GNOME=	gtk12
USE_REINPLACE=	yes
MAKEFILE=	makefile
ALL_TARGET=	euler

post-patch:
	@${REINPLACE_CMD} -e 's|^CC=gcc|CC+= \$$\{CFLAGS\}|g ; \
		 s|[(]INSTALL_DIR[)]|(PREFIX)|g ; \
		 s|-O2||g ; \
		 s|g++|\$$\{CXX\}|g ; \
		 s|gtk-config|\$$\{GTK_CONFIG\}|g ; \
		 s|glib-config|\$$\{GLIB_CONFIG\}|g' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|_DIR,|_DIR |g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/euler ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/help.txt ${DATADIR}
.for dir in progs progs/user
	@${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/../${dir}/*.* ${DATADIR}/${dir}
.endfor
.if !defined(NOPORTDOCS)
.for dir in . french german german/images images reference
	@${MKDIR} ${DOCSDIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/../docs/${dir}/*.* ${DOCSDIR}/${dir}
.endfor
.endif

.include <bsd.port.mk>
