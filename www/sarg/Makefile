# New ports collection makefile for:	sarg
# Date created:		23.02.2003
# Whom:			mt@primats.org.ua
#
# $FreeBSD$
#

PORTNAME=	sarg
PORTVERSION=	2.3.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Squid log analyzer and HTML report generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS=	GD "Enable GD support" on

USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--sysconfdir="${PREFIX}/etc/${PORTNAME}" \
		--enable-sargphp="${PREFIX}/etc/${PORTNAME}" \
		--enable-fontdir="${PREFIX}/etc/${PORTNAME}/fonts" \
		--enable-imagedir="${PREFIX}/etc/${PORTNAME}/images"

MAN1=		sarg.1

.include <bsd.port.pre.mk>

.if ${CC} == "cc"
CC=	gcc
.endif

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif

.if !defined(WITHOUT_GD)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
.endif

pre-install:
	${STRIP_CMD} ${WRKSRC}/sarg

post-extract:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	@${CHMOD} 0755 ${WRKSRC}/configure

post-patch:
.if !defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e '/^LIBS/ s/$$/ -lintl/' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
