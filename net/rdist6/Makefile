PORTNAME=	rdist
PORTVERSION=	6.1.5
PORTREVISION=	10
CATEGORIES=	net
MASTER_SITES=	https://fossies.org/linux/misc/old/ \
		http://www.magnicomp.com/download/rdist/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Network file distribution/synchronisation utility
WWW=		https://www.magnicomp.com/

LICENSE=	BSD4CLAUSE

CONFLICTS=	rdist7

MAKE_JOBS_UNSAFE=	yes

# Years ago base FreeBSD maintained /usr/bin/rdist, but since then it was
# removed. Users who wish to continue to use the rdist6 name can set
# RDIST_NAME=rdist6 in their make.conf. Otherwise we install binary named
# rdist.
RDIST_NAME?=	rdist

INSTALL_TARGET=	install install.man
MAKE_ENV=	BUILD_OPT="${CFLAGS}" BUILD_CLIENT=${RDIST_NAME} \
		STAGEDIR=${STAGEDIR}
PLIST_SUB=	RDIST_NAME=${RDIST_NAME}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
RUN_DEPENDS+=	rsh:net/bsdrcmds
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${RDIST_NAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rdistd

.include <bsd.port.post.mk>
