# New ports collection makefile for:	iiimf-gtk
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	Internet/Intranet Input Method Gtk Client Framework

LIB_DEPENDS=	iiimp.0:${PORTSDIR}/textproc/iiimf-protocol-lib \
		iiimcf.2:${PORTSDIR}/textproc/iiimf-client-lib

BROKEN=		Does not compile

USE_GNOME=	gtk20
USE_X_PREFIX=	yes

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/iiimgcf
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac \
		${WRKSRC}/imaux.c

pre-configure:
	cd ${WRKSRC} && glib-gettextize --force --copy
	cd ${WRKSRC} && intltoolize --copy --force --automake
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../acfiles
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
