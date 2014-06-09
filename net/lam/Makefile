# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	lam
PORTVERSION=	7.1.5b2
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	http://www.lam-mpi.org/download/files/ \
		http://www.thinkingnerds.com/lam/download/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Local Area Multicomputer MPI implementation

USES=		perl5 tar:bzip2 libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rsh=ssh --without-fc
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == ia64 || ${ARCH} == sparc64
# Note: to enable TotalView on 64 bits platforms,
# --enable-tv-dll-force should be added to CONFIGURE_ARGS
PLIST_SUB+=	32BIT_ONLY="@comment "
.else
PLIST_SUB+=	32BIT_ONLY=""
.endif

pre-configure:
	@${REINPLACE_CMD} -E -e 's|/usr/bin/env perl|${PERL} -w| ; \
		s|use warnings;||' ${WRKSRC}/tools/mpiexec/mpiexec

post-install:
.if ${ARCH} != "i386" && ${ARCH} != "powerpc"
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/lam
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
	(cd ${BUILD_WRKSRC}/examples;	\
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif

.include <bsd.port.post.mk>
