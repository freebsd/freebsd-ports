# New ports collection makefile for:	kopete
# Date created:		16 Mar 2003
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kopete
PORTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	KDE instant messaging system (ICQ, AIM, MSN, Jabber, Yahoo, IRC)

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	LDFLAGS="-lcrypto"

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
