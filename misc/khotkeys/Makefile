# New ports collection makefile for:	khotkeys
# Date created:		06 Nov 2000
# Whom:			rse@engelschall.com
#
# $FreeBSD$
#

PORTNAME=	khotkeys
PORTVERSION=	1.0.4
CATEGORIES=	misc kde
MASTER_SITES=	http://dforce.sh.cvut.cz/~seli/en/khotkeys/

MAINTAINER=	ports@FreeBSD.org

USE_KDEBASE_VER=1
NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	"--with-extra-includes=${LOCALBASE}/include"

.include <bsd.port.mk>
