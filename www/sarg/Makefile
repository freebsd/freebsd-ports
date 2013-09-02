# Created by: mt@primats.org.ua
# $FreeBSD$

PORTNAME=	sarg
PORTVERSION=	2.3.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Squid log analyzer and HTML report generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	GD PHP NLS PCRE LDAP ICONV
OPTIONS_DEFAULT=GD PHP NLS PCRE LDAP ICONV

PHP_DESC=	Install PHP for reporting generating

USES=		gmake
USE_AUTOTOOLS=	autoconf aclocal
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	CPPFLAGS=-I${LOCALBASE}/include \
		--sysconfdir="${ETCDIR}" \
		--enable-fontdir="${ETCDIR}/fonts" \
		--enable-imagedir="${ETCDIR}/images"

MAN1=		sarg.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
EXTRA_LDFLAGS=	-lintl
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MGD}
CONFIGURE_ARGS+=--with-gd
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
.else
CONFIGURE_ARGS+=--without-gd
.endif

.if ${PORT_OPTIONS:MPHP}
CONFIGURE_ARGS+=--enable-sargphp="${ETCDIR}"
PLIST_SUB+=	PHP=""
.else
CONFIGURE_ARGS+=--disable-sargphp
PLIST_SUB+=	PHP="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=--with-pcre
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=--without-pcre
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--with-ldap
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--without-ldap
.endif

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=--with-iconv
USES+=	iconv
EXTRA_LDFLAGS+=	-liconv
.else
CONFIGURE_ARGS+=--without-iconv
.endif

post-extract:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	@${CHMOD} 0755 ${WRKSRC}/configure

post-patch:
	@${REINPLACE_CMD} -e '/test .*==/ s/==/=/' \
		${WRKSRC}/configure.in
.if ${PORT_OPTIONS:MNLS} || ${PORT_OPTIONS:MICONV}
	@${REINPLACE_CMD} -e '/^LIBS/ s/$$/ ${EXTRA_LDFLAGS}/' \
		${WRKSRC}/Makefile.in
.endif

pre-configure:
	@(cd ${WRKSRC} && ${AUTORECONF})

.include <bsd.port.mk>
