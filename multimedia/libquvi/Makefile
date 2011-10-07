# New ports collection makefile for:	libquvi
# Date created:		2011-10-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libquvi
PORTVERSION=	0.4.0
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

BUILD_DEPENDS=	libquvi-scripts>=${PORTVERSION}:${PORTSDIR}/multimedia/libquvi-scripts
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	libquvi-scripts>=${PORTVERSION}:${PORTSDIR}/multimedia/libquvi-scripts

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_LUA=	yes
USE_XZ=		yes

MAN3=		libquvi.3

PROJECTHOST=	quvi

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/doc/nd/ && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.mk>
