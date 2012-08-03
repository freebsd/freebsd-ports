# New ports collection makefile for:	sarg
# Date created:		23.02.2003
# Whom:			mt@primats.org.ua
#
# $FreeBSD$
#

PORTNAME=	sarg
PORTVERSION=	2.3.2
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Squid log analyzer and HTML report generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	GD PHP NLS
OPTIONS_DEFAULT=GD PHP NLS

GD_DESC=	Enable GD support
PHP_DESC=	Install PHP for reporting generating

USE_AUTOTOOLS=	autoconf aclocal
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--sysconfdir="${ETCDIR}" \
		--enable-fontdir="${ETCDIR}/fonts" \
		--enable-imagedir="${ETCDIR}/images"

MAN1=		sarg.1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
USE_ICONV=	yes
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
.endif

.if ${PORT_OPTIONS:MPHP}
CONFIGURE_ARGS+=--enable-sargphp="${ETCDIR}"
PLIST_SUB+=	PHP=""
.else
CONFIGURE_ARGS+=--disable-sargphp
PLIST_SUB+=	PHP="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	@${CHMOD} 0755 ${WRKSRC}/configure

post-patch:
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^LIBS/ s/$$/ -lintl/' ${WRKSRC}/Makefile.in
.endif

pre-configure:
	@(cd ${WRKSRC} && ${AUTORECONF})

.include <bsd.port.post.mk>
