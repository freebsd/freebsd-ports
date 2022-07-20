PORTNAME=	lttng-ust
PORTVERSION=	2.4.1
DISTVERSIONSUFFIX=	-4.el7
CATEGORIES=	sysutils linux
MASTER_SITES=	EPEL7/l

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries to instrument and trace user applications (CentOS ${LINUX_DIST_VER})

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	userspace-rcu
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
