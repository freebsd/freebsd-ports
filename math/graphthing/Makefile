# ex:ts=8
# Ports collection makefile for:	GraphThing
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	graphthing
PORTVERSION=	1.3.2
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://graph.seul.org/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A tool that allows you to create, manipulate and study graphs

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk20
USE_BISON=	build
USE_GMAKE=	yes
USE_WX=		2.6
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/graphthing bin/gt

CPPFLAGS=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/graphthing ${PREFIX}/bin
	${LN} -sf graphthing ${PREFIX}/bin/gt

.include <bsd.port.mk>
