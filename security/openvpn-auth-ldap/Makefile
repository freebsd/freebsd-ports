# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	openvpn-auth-ldap
PORTVERSION=	2.0.3
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	auth-ldap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LDAP authentication plugin for OpenVPN

USES=		objc

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c \
		${NONEXISTENT}:${PORTSDIR}/security/openvpn:extract

GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
OPENVPN_WRKSRC=	`cd ${PORTSDIR}/security/openvpn; make -V WRKSRC`
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE} \
			--with-openvpn=${OPENVPN_WRKSRC}/include \
			--with-objc-runtime=GNU

PORTDOCS=	README
PORTEXAMPLES=	auth-ldap.conf
PLIST_FILES=	lib/openvpn-auth-ldap.so
OBJCFLAGS+=	-L/usr/local/lib

OPTIONS_DEFINE=	DOCS EXAMPLES
.include <bsd.port.options.mk>

CONFIGURE_ENV+=	OBJC="${CC}"

post-patch:
	${REINPLACE_CMD} 's|-export-dynamic|-Wl,-export-dynamic|' ${WRKSRC}/configure

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
