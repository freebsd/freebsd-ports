# ex:ts=8
# New ports collection makefile for:	gtkglarea--
# Date created:			Dec 5, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkglareamm
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GtkGLArea-- is a wrapper for the GtkGLArea widget

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	gtkmm-1.2.2:${PORTSDIR}/x11-toolkits/gtkmm12 \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_AUTOTOOLS=	libtool
USE_GL=		yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-lib-GL
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lGL -lGLU \
		${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
