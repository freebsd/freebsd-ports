# New ports collection makefile for:	osb-nrcore
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-nrcore
PORTVERSION=	0.5.2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/gtk-webcore

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ WebCore html rendering engine

BUILD_DEPENDS=	osb-jscore>=0.5.2:${PORTSDIR}/lang/osb-jscore
RUN_DEPENDS=	osb-jscore>=0.5.2:${PORTSDIR}/lang/osb-jscore

USE_XORG=	x11 xt
USE_GNOME=	gnomehack gnometarget gtk20
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g ; \
		 s|-nostdinc++||g ; \
		 s|-nodefaultlibs -lgcc -lc||g; \
		 s|-D.*_DISABLE_DEPRECATED||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
