# New ports collection makefile for:   kmerlin
# Date created:        20 September 2002
# Whom:                Cédric Lamalle
#
# $FreeBSD$
#

PORTNAME=	kmerlin
PORTVERSION=	1.3b3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-1.3Beta3

MAINTAINER=	cedric@cedric.trix.net
COMMENT=	An IM (Instant Messenger) KDE client for the Microsoft MSN Network

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
