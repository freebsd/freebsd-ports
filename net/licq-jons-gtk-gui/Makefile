# New ports collection makefile for:    licq-jons-gtk-gui
# Date created:                         30 November 2002
# Whom:                                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	jons-gtk-gui
PORTVERSION=	${JONS_GTK_LICQ_VER}
CATEGORIES=	net

MAINTAINER=	dinoex@FreeBSD.org

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
LICQ_PORT?=	${PORTSDIR}/net/licq
USE_GNOMENG=	yes
USE_GNOME=	gtk12
PLIST_SUB+=	GUI_NAME=jons-gtk
EXTRA_FIX=	${WRKSRC}/src/Makefile.in

post-patch:
	@ ${MV} ${EXTRA_FIX} ${EXTRA_FIX}.sed
	${SED} -e "s=gtk-config=gtk12-config=" ${EXTRA_FIX}.sed > ${EXTRA_FIX}

.include <bsd.port.pre.mk>
.include "${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>
