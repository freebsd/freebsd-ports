PORTNAME=	libseccomp
PORTVERSION=	2.5.2
DISTVERSIONSUFFIX=	-2.el9
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Enhanced seccomp library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/seccomp/libseccomp

LICENSE=	LGPL21

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
