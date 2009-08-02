# New ports collection makefile for:	osb-browser
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-browser
PORTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-webcore

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ WebCore reference web browser implementation

BUILD_DEPENDS=	osb-nrcit>=0.5.2:${PORTSDIR}/www/osb-nrcit
RUN_DEPENDS=	osb-nrcit>=0.5.2:${PORTSDIR}/www/osb-nrcit

USE_GNOME=	gnomehack gnometarget libglade2
USE_AUTOTOOLS=	libtool:22

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-nostdinc++||g ; \
		 s|-Werror -ansi||g ; \
		 s|-nodefaultlibs -lgcc -lc||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
