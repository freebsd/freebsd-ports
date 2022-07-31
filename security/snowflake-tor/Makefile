PORTNAME=		snowflake
DISTVERSIONPREFIX=	v
PORTVERSION=		2.3.0
CATEGORIES=		security net
PKGNAMESUFFIX=		-tor

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable Transport using WebRTC inspired by Flashproxy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		tor:security/tor

USES=		cpe go:modules
USE_RC_SUBR=	${PORTNAME} ${PORTNAME}-broker
USE_GITHUB=	nodefault
USE_GITLAB=	nodefault
CPE_VENDOR=	torproject
TPO_GEOIP=	7ce4b3d98d01ff33bad8007db3f488d5b172382a
TPO_SNOWFLAKE=	c983c13a84554d0ba1ffcdd054491090c0eafc54


GO_MODULE=      git.torproject.org/pluggable-transports/snowflake.git/v2
GO_BUILDFLAGS=  -ldflags '-s -w -extldflags "-static"'
GO_PKGNAME=	${GO_MODULE}
GO_TARGET=	./broker ./client ./proxy ./server

GL_SITE=	https://gitlab.torproject.org/tpo
GL_TUPLE=	anti-censorship:pluggable-transports/${PORTNAME}:${TPO_SNOWFLAKE}:tpo_acs_snowflake/vendor/git.torproject.org/pluggable-transports/snowflake.git/v2 \
		anti-censorship:geoip:${TPO_GEOIP}:tpo_acs_geoip/vendor/gitlab.torproject.org/tpo/anti-censorship/geoip

GH_TUPLE=	torbsd:goptlib:v1.2.0:torbsd_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git

PLIST_SUB=	MANPAGES=${MANPAGES}
SUB_FILES=	pkg-message

pre-extract:
	${MKDIR} ${WRKDIR}/pluggable-transports ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} && \
	${RLN} ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} ${WRKDIR}/pluggable-transports/.

post-patch:
	${REINPLACE_CMD} "s|/usr/share|${PREFIX}/share|g" \
	  ${WRKDIR}/${GO_MODULE}@v${PORTVERSION}/broker/broker.go

post-install:
	${MKDIR} ${STAGEDIR}/${MANPREFIX}/man/man1
.	for b in client proxy
	  ${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}-$b.1 ${STAGEDIR}/${MANPREFIX}/man/man1
	  ${MV} ${STAGEDIR}/${PREFIX}/bin/$b ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-$b
.	endfor
	${MV} ${STAGEDIR}/${PREFIX}/bin/broker ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-broker
	${MV} ${STAGEDIR}/${PREFIX}/bin/server ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
