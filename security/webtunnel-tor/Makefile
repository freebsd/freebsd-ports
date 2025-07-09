PORTNAME=	webtunnel
PORTVERSION=	0.0.1
PORTREVISION=	15
CATEGORIES=	security net
PKGNAMESUFFIX=	-tor

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable Transport attempting to imitate web browsing based on HTTPT
WWW=		https://gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/webtunnel

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${TPO_WEBTUN}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		tor:security/tor

USES=		cpe go
USE_GITLAB=	yes
CPE_VENDOR=	torproject
TPO_GOPTLIB=	24b2b145d7afc66b66e58c702cf988c00f694b70
TPO_WEBTUN=	38eb55054a5c3c072acc1d8f9a9afa36e3a5c9b7

CGO_ENABLED=	0
GO_BUILDFLAGS=	-ldflags '${STRIP} -w -extldflags "-static"'
GO_PKGNAME=	gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/webtunnel
GO_TARGET=	./main/client ./main/server

GL_SITE=	https://gitlab.torproject.org/tpo
GL_ACCOUNT=	anti-censorship/pluggable-transports
GL_TAGNAME=	${TPO_WEBTUN}
GL_TUPLE=	anti-censorship:pluggable-transports/goptlib:${TPO_GOPTLIB}:tpo_ac_ptlib/vendor/gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/goptlib

PLIST_FILES=	bin/${PORTNAME}-tor-client \
		bin/${PORTNAME}-tor-server
pre-extract:
	${MKDIR} ${WRKDIR}/pluggable-transports
	${LN} -sf ${WRKDIR}/webtunnel-${TPO_WEBTUN} ${WRKDIR}/pluggable-transports/webtunnel-${TPO_WEBTUN}
	${LN} -sf ${WRKDIR}/goptlib-${TPO_GOPTLIB} ${WRKDIR}/pluggable-transports/goptlib-${TPO_GOPTLIB}

post-install:
	${MV} ${STAGEDIR}/${PREFIX}/bin/client ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-tor-client
	${MV} ${STAGEDIR}/${PREFIX}/bin/server ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}-tor-server

.include <bsd.port.mk>
