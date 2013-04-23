# Created by: Dave Grochowski <malus.x@gmail.com>
# $FreeBSD$

PORTNAME=	otr
PORTVERSION=	0.7
PORTREVISION=	6
CATEGORIES=	security net-im kde
MASTER_SITES=	http://kopete-otr.follefuder.org/
PKGNAMEPREFIX=	kopete-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	malus.x@gmail.com
COMMENT=	Allows deniable private conversations using Kopete

BUILD_DEPENDS=	kopete:${PORTSDIR}/net-im/kopete
RUN_DEPENDS=	kopete:${PORTSDIR}/net-im/kopete
LIB_DEPENDS=	otr.4:${PORTSDIR}/security/libotr3

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USES=		pkgconfig
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
