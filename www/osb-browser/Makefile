# New ports collection makefile for:	osb-browser
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-browser
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-webcore

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk-Webcore example web browser

LIB_DEPENDS=	nrcit.0:${PORTSDIR}/www/osb-nrcit

USE_X_PREFIX=	yes
USE_GNOME=	libglade2 gnomehack gnomeprefix
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||; s|-nostdinc++||; \
		s|-nodefaultlibs||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
