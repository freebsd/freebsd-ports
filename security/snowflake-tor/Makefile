PORTNAME=		snowflake
DISTVERSIONPREFIX=	v
DISTVERSION=		2.11.0
PORTREVISION=	1
CATEGORIES=		security net
PKGNAMESUFFIX=		-tor

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable Transport using WebRTC inspired by Flashproxy
WWW=		https://snowflake.torproject.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		tor:security/tor

USES=		cpe go:modules
USE_RC_SUBR=	${PORTNAME} ${PORTNAME}-broker
CPE_VENDOR=	torproject

GO_MODULE=      gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/snowflake/v2
GO_BUILDFLAGS=  -ldflags '${STRIP} -w -extldflags "-static"'
GO_PKGNAME=	${GO_MODULE}
GO_TARGET=	./broker ./client ./proxy ./server

PLIST_SUB=	MANPAGES=${MANPAGES}
SUB_FILES=	pkg-message

post-extract:
	# inspired by Mk/Uses/go.mk
.for target in ${GO_TARGET}
	cd ${GO_WRKSRC}/${target} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy -e && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod vendor -e
.endfor

post-patch:
	${REINPLACE_CMD} "s|/usr/share|${PREFIX}/share|g" \
		${WRKSRC}/broker/broker.go

post-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/man/man1
.for b in client proxy
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}-$b.1 ${STAGEDIR}/${PREFIX}/share/man/man1
	${MV} ${STAGEDIR}/${PREFIX}/bin/$b ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-$b
.endfor
	${MV} ${STAGEDIR}/${PREFIX}/bin/broker ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-broker
	${MV} ${STAGEDIR}/${PREFIX}/bin/server ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
