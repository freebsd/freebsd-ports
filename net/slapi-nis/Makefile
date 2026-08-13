PORTNAME=	slapi-nis
DISTVERSION=	0.70.0
CATEGORIES=	net
MASTER_SITES=	https://codeberg.org/freeipa/slapi-nis/archive/

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Schema Compatibility plugin for 389 Directory Server
WWW=		https://codeberg.org/freeipa/slapi-nis

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/dirsrv/slapi-plugin.h:net/389-ds-base
LIB_DEPENDS=	libldap.so:net/openldap26-client \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libsss_nss_idmap.so:security/sssd2
RUN_DEPENDS=	389-ds-base>=0:net/389-ds-base

USES=		autoreconf gmake libtool localbase:ldflags pkgconfig

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-nis \
		--disable-static \
		--enable-be-txns-by-default \
		--with-idviews \
		--with-ldap=openldap \
		--with-nsswitch \
		--with-pam \
		--with-pam-service=system \
		--with-server=dirsrv \
		--with-sss-nss-idmap

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	lib/dirsrv/plugins/schemacompat-plugin.so

.include <bsd.port.mk>
