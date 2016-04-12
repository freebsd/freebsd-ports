# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blastbeat
PORTVERSION=	20121205
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	vg@FreeBSD.org
COMMENT=	High-performance HTTP/HTTPS/SPDY proxy

LICENSE=	UNBIT
LICENSE_NAME=	UNBIT
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept

LIB_DEPENDS=	libev.so:devel/libev \
		libuuid.so:misc/e2fsprogs-libuuid \
		libzmq.so:net/libzmq2

USES=		gmake
USE_OPENSSL=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_TAGNAME=	cdac9a9
PORTEXAMPLES=	*

CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PLIST_FILES=	bin/blastbeat \
		%%ETCDIR%%/blastbeat.ini.sample

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${ETCDIR} && \
		${INSTALL} ${WRKSRC}/${PORTNAME}.ini ${STAGEDIR}${ETCDIR}/${PORTNAME}.ini.sample
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
