PORTNAME=	libsecret
PORTVERSION=	0.20.4
DISTVERSIONSUFFIX=	-4.el9
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library for storing and retrieving passwords and other secrets
WWW=		https://wiki.gnome.org/Projects/Libsecret/

LICENSE=	LGPL20+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libgcrypt libgpg-error
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
