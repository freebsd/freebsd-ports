# ex:ts=8
# Ports collection makefile for:	GraphThing
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	graphthing
PORTVERSION=	1.2.1
CATEGORIES=	math
MASTER_SITES=	http://graph.seul.org/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A tool that allows you to create, manipulate and study graphs

LIB_DEPENDS=	wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk20
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-wx-config=${X11BASE}/bin/wxgtk2-2.6-config
MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/graphthing bin/gt

CPPFLAGS=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/graphthing ${PREFIX}/bin
	${LN} -sf graphthing ${PREFIX}/bin/gt

.include <bsd.port.mk>
