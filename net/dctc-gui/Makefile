# New ports collection makefile for:	GUI to Direct Connect Text Client
# Date created:				Thu Nov 22 00:34:48 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dctc
PORTVERSION=	0.33
CATEGORIES=	net gnome
MASTER_SITES=	http://ac2i.tzo.com/dctc/
PKGNAMESUFFIX=	-gui
DISTNAME=	dc_gui-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	dctc:${PORTSDIR}/net/dctc
LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit \
		iconv.2:${PORTSDIR}/converters/iconv \
		intl.1:${PORTSDIR}/devel/gettext

USE_GNOMELIBS=	yes
USE_GTK=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnome=${X11BASE} \
		--with-gtk-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}

DOC_FILES=	COPYING ChangeLog

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}${PKGNAMESUFFIX}
.endfor
.endif

.include <bsd.port.mk>
