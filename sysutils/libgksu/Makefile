# New ports collection makefile for:   libgksu1.2
# Date created:        1 October 2004
# Whom:                Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
#
# $FreeBSD$
#

PORTNAME=	libgksu
PORTVERSION=	1.3.8
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/libgksu1.2/
DISTNAME=	${PORTNAME}1.2-${PORTVERSION}

MAINTAINER=	bsam@ipt.ru
COMMENT=	Library providing su and sudo functionality

RUN_DEPENDS=	xauth:${X_CLIENTS_PORT} \
		sudo:${PORTSDIR}/security/sudo

USE_GNOME=	pkgconfig glib20
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-gtk-doc=no
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
