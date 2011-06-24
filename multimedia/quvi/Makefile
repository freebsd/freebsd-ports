# New ports collection makefile for:	quvi
# Date created:		2 February 2010
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	quvi
PORTVERSION=	0.2.17
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Query video library for Youtube like websites

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

OPTIONS=	NSFW "Enable adult website support" off

LICENSE=	GPLv3

CPPFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_LUA=	yes
USE_XZ=		yes

MAN1=		quvi.1

.include <bsd.port.options.mk>

.if defined(WITH_NSFW)
CONFIGURE_ARGS+=--enable-nsfw
PLIST_SUB+=	NSFW=""
.else
PLIST_SUB+=	NSFW="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/doc/nd/ && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.mk>
