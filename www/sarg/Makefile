# Created by: mt@primats.org.ua
# $FreeBSD$

PORTNAME=	sarg
PORTVERSION=	2.4.0
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Squid log analyzer and HTML report generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	GD PHP NLS PCRE LDAP ICONV
OPTIONS_DEFAULT=GD PHP PCRE LDAP ICONV
OPTIONS_SUB=	yes

PHP_DESC=	Install PHP for reporting generating

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir="${ETCDIR}" \
		--enable-fontdir="${ETCDIR}/fonts" \
		--enable-imagedir="${ETCDIR}/images"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=		-lintl
GD_CONFIGURE_WITH=	gd
GD_LIB_DEPENDS=		libgd.so:graphics/gd
PHP_CONFIGURE_ON=	--enable-sargphp="${ETCDIR}"
PHP_CONFIGURE_OFF=	--disable-sargphp
PCRE_CONFIGURE_WITH=	pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
LDAP_USE=		USE_OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap
ICONV_USES=		iconv
ICONV_CONFIGURE_WITH=	iconv
ICONV_LDFLAGS=		${ICONV_LIB}

.include <bsd.port.mk>
