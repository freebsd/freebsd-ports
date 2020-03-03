# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	openvpn-auth-ldap
PORTVERSION=	2.0.4
DISTVERSIONPREFIX=	auth-ldap-
CATEGORIES=	security net-vpn

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	LDAP authentication plugin for OpenVPN

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	re2c:devel/re2c \
		check>=0:devel/check \
		libobjc2>=0:lang/libobjc2 \
		${LOCALBASE}/include/openvpn-plugin.h:security/openvpn

# this port doesn't require ssl itself, but OpenLDAP needs it
# and https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=235776
# appears to document issues on some systems when --with-openssl
# is missing.
USES=		autoreconf objc ssl tar:xz

GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE} \
			--with-openvpn=${LOCALBASE}/include \
			--with-objc-runtime=GNU \
			--with-openssl=${OPENSSLBASE}

USE_GITHUB=	yes
GH_ACCOUNT=	threerings
GH_PROJECT=	openvpn-auth-ldap

PORTDOCS=	README
PORTEXAMPLES=	auth-ldap.conf
PLIST_FILES=	lib/openvpn-auth-ldap.so
OBJCFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include -fPIC
CFLAGS+=	-fPIC

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

CONFIGURE_ENV+=	OBJC="${CC}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn-auth-ldap.so
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/auth-ldap.conf ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

CC+=		${DEBUG_FLAGS}

.include <bsd.port.post.mk>
