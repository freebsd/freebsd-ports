# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

BUILD_DEPENDS=	libquvi-scripts>=0.4.0:${PORTSDIR}/multimedia/libquvi-scripts
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	libquvi-scripts>=0.4.0:${PORTSDIR}/multimedia/libquvi-scripts

OPTIONS_DEFINE=	DOCS

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_LUA=	yes
USE_XZ=		yes
USES=		pathfix

MAN3=		libquvi.3

PROJECTHOST=	quvi

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/doc/nd/ && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.mk>
