# Created by: Kristof Provost <kp@FreeBSD.org>

PORTNAME=	libpfctl
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	LOCAL/kp/
DISTFILES=	libpfctl-${_LIBPFCTL_HASH}.tar.gz

MAINTAINER=	kp@FreeBSD.org
COMMENT=	Library for interaction with pf(4)

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_11=	Will not work until nvlist-ified ioctls are available
BROKEN_FreeBSD_12=	Will not work until nvlist-ified ioctls are available
BROKEN_FreeBSD_13=	Will not work until nvlist-ified ioctls are available

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libpfctl

_LIBPFCTL_HASH=	4ae3a97e127c

PLIST_FILES=	lib/libpfctl.so.0 \
		include/libpfctl.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libpfctl.so.0 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include

.if defined(MAINTAINER_MODE)
upload:
	cd /usr/src/lib && \
	HASH=$$(git rev-parse --short origin/main) && \
	git archive --format=tar.gz \
		--output=libpfctl-$${HASH}.tar.gz \
		origin/main libpfctl && \
	scp libpfctl-$${HASH}.tar.gz kp@freefall.freebsd.org:public_distfiles/
.endif

.include <bsd.port.mk>
