# New ports collection makefile for:	xlogmaster
# Date created:		1 August 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $FreeBSD$
#

PORTNAME=	xlogmaster
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick & easy monitoring of logfiles and devices

USE_GNOME=	gtk12
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		xlogmaster.1
INFO=		xlogmaster

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

post-extract:
	-${RM} ${WRKSRC}/import/getopt*

post-install:
	@install-info ${PREFIX}/info/xlogmaster.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${FILESDIR}/xlogmasterrc ${PREFIX}/etc/xlogmaster

.include <bsd.port.mk>
