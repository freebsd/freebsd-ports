# New ports collection makefile for:   kmerlin
# Date created:        20 September 2002
# Whom:                Cédric Lamalle
#
# $FreeBSD$
#

PORTNAME=	kmerlin
PORTVERSION=	1.4.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	cedric@cedric.trix.net
COMMENT=	An IM (Instant Messenger) KDE client for the Microsoft MSN Network

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
_NO_KDE_FIXPTHREAD=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
