# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blastbeat
PORTVERSION=	20121205
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	GH GHC

MAINTAINER=	vg@FreeBSD.org
COMMENT=	High-performance HTTP/HTTPS/SPDY proxy

LICENSE=	UNBIT
LICENSE_NAME=	UNBIT
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept

LIB_DEPENDS=	ev:${PORTSDIR}/devel/libev \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		zmq:${PORTSDIR}/net/libzmq2

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_COMMIT=	cdac9a9
GH_TAGNAME=	${GH_COMMIT}
PORTEXAMPLES=	*

CFLAGS+=	-I${LOCALBASE}/include \
		-L${LOCALBASE}/lib

PLIST_FILES=	bin/blastbeat \
		%%ETCDIR%%/blastbeat.ini.sample
PLIST_DIRSTRY=	%%ETCDIR%%

OPTIONS_DEFINE=	EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${ETCDIR} && \
		${INSTALL} ${WRKSRC}/${PORTNAME}.ini ${ETCDIR}/${PORTNAME}.ini.sample

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
