# New ports collection makefile for:    licq-jons-gtk-gui
# Date created:                         30 November 2002
# Whom:                                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	jons-gtk-gui
PORTVERSION=	${JONS_GTK_LICQ_VER}
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	licq
PKGNAMEPREFIX=		licq-
DISTNAME=		${PKGNAMEPREFIX}${LICQ_VER}
#DISTFILES=		${DISTNAME}.tar.bz2

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Jons GTK plugin for licq

RUN_DEPENDS+=	licq:${PORTSDIR}/${LICQ_PORT}

IGNORE=		is incompatible with licq-1.3.0
DEPRECATED=	project stalled, no more releases
EXPIRATION_DATE=	2005-04-01

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
LICQ_PORT?=	net/licq
USE_GNOME=	gtk12
PLIST_SUB+=	GUI_NAME=jons-gtk
EXTRA_FIX=	${WRKSRC}/src/Makefile.in
LICQ_VER=		1.2.4
JONS_GTK_LICQ_VER=	0.20.3

post-patch:
	@ ${MV} ${EXTRA_FIX} ${EXTRA_FIX}.sed
	${SED} -e "s=gtk-config=gtk12-config=" ${EXTRA_FIX}.sed > ${EXTRA_FIX}

.include <bsd.port.pre.mk>

WRKSRC?=		${WRKDIR}/${DISTNAME}/plugins/${PORTNAME}

.if ${OSVERSION} > 500030
CPPFLAGS+=		-Wno-deprecated
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		CPPFLAGS="${CPPFLAGS}"
.endif

.include <bsd.port.post.mk>
