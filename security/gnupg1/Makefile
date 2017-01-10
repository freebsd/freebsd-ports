# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	1.4.21
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GNUPG
PKGNAMESUFFIX=	1

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	The GNU Privacy Guard (minimalist "classic" version)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CPE_VENDOR=	gnupg

USES=		charsetfix compiler cpe gmake readline tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-camellia \
		--enable-noexecstack

INFO=		gnupg1
DOCSDIR=	${PREFIX}/share/doc/gnupg1
PORTDOCS=	*

TEST_TARGET=	check

OPTIONS_DEFINE=	CURL DOCS LDAP ICONV LIBUSB NLS SUID_GPG
OPTIONS_DEFAULT=CURL
OPTIONS_SUB=	yes

CURL_DESC=	Use libcurl for the keyserver interface
LDAP_DESC=	LDAP keyserver interface
LIBUSB_DESC=	Support for USB smart cards
SUID_GPG_DESC=	Install GPG setuid

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl=${LOCALBASE}
# Work around a GnuPG configure buglet
CURL_CONFIGURE_ENV=	_libcurl_config=${LOCALBASE}/bin/curl-config

ICONV_USES=		iconv
ICONV_CONFIGURE_ENABLE=	gnupg-iconv

LIBUSB_CONFIGURE_WITH=	libusb=${LOCALBASE}

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap=${LOCALBASE}

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${COMPILER_TYPE} == "clang"
CFLAGS+=	-fheinous-gnu-extensions
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in doc/DETAILS doc/FAQ doc/HACKING doc/OpenPGP \
	ABOUT-NLS AUTHORS BUGS COPYING INSTALL NEWS PROJECTS \
	README THANKS TODO VERSION
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
