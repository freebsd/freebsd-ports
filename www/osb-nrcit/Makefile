# New ports collection makefile for:	osb-nrcit
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-nrcit
PORTVERSION=	0.5.2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/gtk-webcore/gtk-webcore/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ WebCore embeddable web browser component

BUILD_DEPENDS=	osb-nrcore>=0.5.2:${PORTSDIR}/www/osb-nrcore
LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	osb-nrcore>=0.5.2:${PORTSDIR}/www/osb-nrcore

USE_GNOME=	gnomehack gnometarget gtk20 librsvg2
USE_AUTOTOOLS=	libtool:22
CONFGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		Does not compile on !i386 and !amd64
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g ; \
		 s|-nostdinc++||g ; \
		 s|-Werror||g ; \
		 s|-nodefaultlibs -lgcc -lc||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
