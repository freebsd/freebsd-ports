# $FreeBSD$

PORTNAME=	apt-cacher-ng
PORTVERSION=	3.2
CATEGORIES=	www
MASTER_SITES=	DEBIAN_POOL/apt-cacher-ng
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	keve@keve.hu
COMMENT=	Specialized http/s proxy for caching software distribution sites

LICENSE=	EduardBloch
LICENSE_NAME=	Eduard Bloch license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c++11-lang cmake ssl tar:xz
USE_RC_SUBR=	apt_cacher_ng

CMAKE_ARGS=	-DLIBDIR:PATH=${DATADIR} \
		-DMANDIR:PATH=${PREFIX}/man \
		-Dopenssl_FOUND=1 \
		-Dopenssl_CFLAGS="-I ${OPENSSLINC}" \
		-Dopenssl_LDFLAGS="-L ${OPENSSLLIB} -lssl -lcrypto"
CMAKE_ON=	USE_SSL
SUB_FILES=	backends_debian backends_freebsd backends_ubuntu \
		freebsd_mirrors pkg-message

OPTIONS_DEFINE=	DOCS FUSE
OPTIONS_SUB=	yes

FUSE_DESC=	FUSE support for interfacing with the proxy via acngfs

FUSE_CMAKE_BOOL=	USE_FUSE
FUSE_USES=		fuse pkgconfig

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/acng.conf ${STAGEDIR}${ETCDIR}/acng.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/security.conf ${STAGEDIR}${ETCDIR}/security.conf.sample
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
.for f in backends_debian backends_freebsd backends_ubuntu
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${INSTALL_DATA} ${WRKDIR}/freebsd_mirrors ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}/var/cache/apt-cacher-ng \
		${STAGEDIR}/var/log/apt-cacher-ng

.include <bsd.port.mk>
