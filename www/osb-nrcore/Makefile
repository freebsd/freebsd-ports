# New ports collection makefile for:	osb-nrcore
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-nrcore
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-webcore

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk-Webcore's browser engine

LIB_DEPENDS=	jscore.0:${PORTSDIR}/lang/osb-jscore

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gtk20 gnomehack
USE_GCC=	3.4
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -DNDEBUG" \
		LDFLAGS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${ARCH}=="alpha" || ${OSVERSION} < 500000
BROKEN=	Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||; s|-nostdinc++||' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
