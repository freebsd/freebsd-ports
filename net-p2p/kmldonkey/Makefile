# New ports collection makefile for:	KMLDonkey
# Date created:		Thu Feb 20 22:04:46 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmldonkey
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	net-p2p kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE3.x/network
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.pre/pre/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE integration for MLDonkey eDonkey P2P client

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--program-transform-name=''
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

MAN1=	kmldonkey.1 kmldonkey_submit.1

.include <bsd.port.mk>
