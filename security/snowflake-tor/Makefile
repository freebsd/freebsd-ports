PORTNAME=		snowflake
DISTVERSIONPREFIX=	v
PORTVERSION=		2.5.1
PORTREVISION=	23
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
TPO_SNOWFLAKE=	7b77001eaa90e09d41172a2b170dabd3f1922b4a

GO_MODULE=      git.torproject.org/pluggable-transports/snowflake.git/v2
GO_BUILDFLAGS=  -ldflags '${STRIP} -w -extldflags "-static"'
GO_PKGNAME=	${GO_MODULE}
GO_TARGET=	./broker ./client ./proxy ./server

GL_SITE=	https://gitlab.torproject.org/tpo
GL_TUPLE=	anti-censorship:pluggable-transports/${PORTNAME}:${TPO_SNOWFLAKE}:tpo_acs_snowflake/vendor/git.torproject.org/pluggable-transports/snowflake.git/v2 \
		anti-censorship:geoip:${TPO_GEOIP}:tpo_acs_geoip/vendor/gitlab.torproject.org/tpo/anti-censorship/geoip

GH_TUPLE=	torbsd:goptlib:v1.2.0:torbsd_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git \
		golang:mod:v0.8.0:mod \
		golang:net:v0.8.0:net \
		golang:sys:v0.6.0:sys \
		golang:text:v0.8.0:text \
		golang:tools:v0.6.0:tools \
		templexxx:cpu:v0.1.0:cpu

PLIST_SUB=	MANPAGES=${MANPAGES}
SUB_FILES=	pkg-message

pre-extract:
	${MKDIR} ${WRKDIR}/pluggable-transports ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} && \
	${RLN} ${WRKDIR}/${PORTNAME}-${TPO_SNOWFLAKE} ${WRKDIR}/pluggable-transports/.

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

post-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/man/man1
.	for b in client proxy
	  ${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}-$b.1 ${STAGEDIR}/${PREFIX}/share/man/man1
	  ${MV} ${STAGEDIR}/${PREFIX}/bin/$b ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-$b
.	endfor
	${MV} ${STAGEDIR}/${PREFIX}/bin/broker ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-broker
	${MV} ${STAGEDIR}/${PREFIX}/bin/server ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
