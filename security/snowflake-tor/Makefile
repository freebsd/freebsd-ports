PORTNAME=		snowflake
DISTVERSIONPREFIX=	v
DISTVERSION=		2.11.0
CATEGORIES=		security net
PKGNAMESUFFIX=		-tor

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable Transport using WebRTC inspired by Flashproxy
WWW=		https://snowflake.torproject.org/

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
TPO_SNOWFLAKE=6472bd86cdd5d13fe61dc851edcf83b03df7bda1
TPO_GOPTLIB=f4bb5dd5725833bd880347b8fbaf60522ed0a710

GO_MODULE=      gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/snowflake/v2
GO_BUILDFLAGS=  -ldflags '${STRIP} -w -extldflags "-static"'
GO_PKGNAME=	${GO_MODULE}
GO_TARGET=	./broker ./client ./proxy ./server

GL_SITE=	https://gitlab.torproject.org/tpo
GL_TUPLE=	anti-censorship:pluggable-transports/${PORTNAME}:${TPO_SNOWFLAKE}:tpo_acs_snowflake/vendor/gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/snowflake \
		anti-censorship:geoip:${TPO_GEOIP}:tpo_acs_geoip/vendor/gitlab.torproject.org/tpo/anti-censorship/geoip \
		anti-censorship:pluggable-transports/goptlib:${TPO_GOPTLIB}:tpo_acs_goptlib/vendor/gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/goptlib

GH_TUPLE=golang:mod:v0.30.0:mod \
		golang:net:v0.47.0:net \
		golang:sys:v0.38.0:sys \
		golang:text:v0.22.0:text \
		golang:tools:v0.30.0:tools \
		templexxx:cpu:v0.1.1:cpu

PLIST_SUB=	MANPAGES=${MANPAGES}
SUB_FILES=	pkg-message

pre-extract:
	${MKDIR} ${WRKDIR}/pluggable-transports ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} && \
	${RLN} ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} ${WRKDIR}/pluggable-transports/. && \
	${MKDIR} ${WRKDIR}/pluggable-transports ${WRKDIR}/goptlib-${TPO_GOPTLIB} && \
	${RLN} ${WRKDIR}/goptlib-${TPO_GOPTLIB} ${WRKDIR}/pluggable-transports/.

pre-patch:
.for m in mod net sys text tools
	${RM} -r ${WRKSRC}/vendor/golang.org/x/$m
	${LN} -s ${WRKDIR}/$m-* ${WRKSRC}/vendor/golang.org/x/$m
.endfor
	${RM} -r ${WRKSRC}/vendor/github.com/templexxx/cpu
	${LN} -s ${WRKDIR}/cpu-* ${WRKSRC}/vendor/github.com/templexxx/cpu

post-patch:
	${REINPLACE_CMD} "s|/usr/share|${PREFIX}/share|g" \
	  ${WRKDIR}/${GO_MODULE}@v${PORTVERSION}/broker/broker.go
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_CMD} mod vendor

post-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/man/man1
.	for b in client proxy
	  ${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}-$b.1 ${STAGEDIR}/${PREFIX}/share/man/man1
	  ${MV} ${STAGEDIR}/${PREFIX}/bin/$b ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-$b
.	endfor
	${MV} ${STAGEDIR}/${PREFIX}/bin/broker ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-broker
	${MV} ${STAGEDIR}/${PREFIX}/bin/server ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
