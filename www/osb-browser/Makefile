# New ports collection makefile for:	osb-browser
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-browser
PORTVERSION=	0.5.2
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/gtk-webcore/gtk-webcore/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ WebCore reference web browser implementation

DEPRECATED=     Abandonware, please use www/webkit-gtk2
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	osb-nrcit>=0.5.2:${PORTSDIR}/www/osb-nrcit
RUN_DEPENDS=	osb-nrcit>=0.5.2:${PORTSDIR}/www/osb-nrcit

USE_GNOME=	gnomehack gnometarget libglade2
USE_AUTOTOOLS=	libtool

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-nostdinc++||g ; \
		 s|-DGTK_DISABLE_DEPRECATED||g ; \
		 s|-Werror -ansi||g ; \
		 s|-nodefaultlibs -lgcc -lc||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
