PORTNAME=	libpfctl
PORTVERSION=	0.8
CATEGORIES=	net
MASTER_SITES=	LOCAL/kp/

MAINTAINER=	kp@FreeBSD.org
COMMENT=	Library for interaction with pf(4)
WWW=		https://cgit.freebsd.org/src/tree/lib/libpfctl

LICENSE=	BSD2CLAUSE

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libpfctl

_LIBPFCTL_HASH=	498934c5ff51
_LIBPFCTL_REV=	2

PLIST_FILES=	\
		lib/libpfctl.so \
		lib/libpfctl.so.0 \
		include/libpfctl.h

.include <bsd.port.pre.mk>

.if ${OSREL} == "15.0"
DISTFILES=	libpfctl-${_LIBPFCTL_HASH}.tar.gz
.else
DISTFILES=	libpfctl-${OSREL}_${_LIBPFCTL_REV}.tar.gz
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libpfctl.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -s libpfctl.so.0 ${STAGEDIR}${PREFIX}/lib/libpfctl.so
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include

.if defined(MAINTAINER_MODE)
upload:
	for version in 12.4 13.2 14.0; \
	do \
		cd /usr/src/lib && \
		git archive --format=tar.gz \
		    --output=libpfctl-$${version}_${_LIBPFCTL_REV}.tar.gz \
		    libpfctl/$${version} libpfctl ; \
	done
	cd /usr/src/lib && \
	git archive --format=tar.gz \
	    --output=libpfctl-${_LIBPFCTL_HASH}.tar.gz \
	    ${_LIBPFCTL_HASH} libpfctl ;
.endif

.include <bsd.port.post.mk>
