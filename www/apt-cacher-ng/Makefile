PORTNAME=	apt-cacher-ng
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	DEBIAN_POOL/apt-cacher-ng
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	keve@keve.hu
COMMENT=	Specialized http/s proxy for caching software distribution sites
WWW=		https://www.unix-ag.uni-kl.de/~bloch/acng/

LICENSE=	EduardBloch
LICENSE_NAME=	Eduard Bloch license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Outdated and unsupported version, current version was released in 2020 and upstream is still active
EXPIRATION_DATE=2024-06-14

USES=		compiler:c++11-lang cmake cpe tar:xz
CPE_VENDOR=	${PORTNAME}_project

USE_RC_SUBR=	apt_cacher_ng

CMAKE_ARGS=	-DLIBDIR:PATH=${DATADIR} \
		-DMANDIR:PATH=${PREFIX}/share/man

SUB_FILES=	backends_debian backends_freebsd backends_ubuntu \
		freebsd_mirrors pkg-message

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS SSL FUSE
OPTIONS_DEFAULT=	SSL
OPTIONS_SUB=	yes

FUSE_DESC=	FUSE support for interfacing with the proxy via acngfs
SSL_DESC=	SSL support to allow proxying https sites

FUSE_USES=		fuse pkgconfig
FUSE_CMAKE_BOOL=	USE_FUSE
SSL_USES=	ssl
SSL_CMAKE_BOOL=	USE_SSL
SSL_CMAKE_ON=	-Dopenssl_FOUND=1 \
		-Dopenssl_CFLAGS="-I ${OPENSSLINC}" \
		-Dopenssl_LDFLAGS="-L ${OPENSSLLIB} -lssl -lcrypto"

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
