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
OPTIONS_SUB=	PHP NLS

PHP_DESC=	Install PHP for reporting generating

USES=		gmake
USE_AUTOTOOLS=	autoconf aclocal
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	CPPFLAGS=-I${LOCALBASE}/include \
		--sysconfdir="${ETCDIR}" \
		--enable-fontdir="${ETCDIR}/fonts" \
		--enable-imagedir="${ETCDIR}/images"

NLS_USES=		gettext
NLS_LDFLAGS=		-lintl
NLS_CONFIGURE_ENABLE=	nls
GD_CONFIGURE_WITH=	gd
GD_LIB_DEPENDS=		libgd.so:${PORTSDIR}/graphics/gd
PHP_CONFIGURE_ON=	--enable-sargphp="${ETCDIR}"
PHP_CONFIGURE_OFF=	--disable-sargphp
PCRE_CONFIGURE_WITH=	pcre
PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
LDAP_USE=		USE_OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap
ICONV_USES=		iconv
ICONV_CONFIGURE_WITH=	iconv
ICONV_LDFLAGS=		${ICONV_LIB}

post-extract:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	@${CHMOD} 0755 ${WRKSRC}/configure

post-patch:
	@${REINPLACE_CMD} -e '/test .*==/ s/==/=/' \
		${WRKSRC}/configure.in

pre-configure:
	@(cd ${WRKSRC} && ${AUTORECONF})

.include <bsd.port.mk>
