# New ports collection makefile for:	openvpn
# Date created:		2010-02-19
# Whom:			Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	openvpn
DISTVERSION=	201230
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.secure-computing.net/pub/FreeBSD/ports/openvpn-devel/ \
		ftp://ftp2.secure-computing.net/pub/FreeBSD/ports/openvpn-devel/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	Secure IP/Ethernet tunnel daemon

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}

CONFLICTS_INSTALL=	openvpn-[0-9]* openvpn-beta-[0-9]*

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install mandir=${MANPREFIX}/man

LIB_DEPENDS+=	lzo2.2:${PORTSDIR}/archivers/lzo2

MAN8=		openvpn.8

OPTIONS=	PW_SAVE "Interactive passwords may be read from a file" off \
		PKCS11  "Use security/pkcs11-helper" off \
		EXAMPLES "Install sample configs and scripts" off \
		POLARSSL "Build will PolarSSL instead of OpenSSL" off

USE_RC_SUBR=	openvpn
USE_LDCONFIG=	${PREFIX}/lib

SUB_FILES=	pkg-message
SUB_LIST+=	OSVERSION=${OSVERSION}

.if defined(PACKAGE_BUILDING)
WITHOUT_CHECK=	yes
.endif

.if defined (WITH_POLARSSL)
BUILD_DEPENDS+=		libpolarssl.so:${PORTSDIR}/security/polarssl
CONFIGURE_ARGS+=	--with-crypto-lib=polarssl
.else
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

.ifdef (LOG_OPENVPN)
CFLAGS+=	-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

pre-fetch:
.ifdef (LOG_OPENVPN)
	@${ECHO} "Building with LOG_OPENVPN=${LOG_OPENVPN}"
.else
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      LOG_OPENVPN={Valid syslog facility}"
	@${ECHO} "      EXAMPLE:  make LOG_OPENVPN=LOG_DAEMON"
	@${ECHO} ""
.endif

.if defined(WITH_PW_SAVE)
CONFIGURE_ARGS+=	--enable-password-save
.endif

.if defined(WITH_PKCS11)
LIB_DEPENDS+=	pkcs11-helper.1:${PORTSDIR}/security/pkcs11-helper
.else
CONFIGURE_ARGS+=	--disable-pkcs11
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${FIND} ${WRKSRC} -name \*.bak -delete

post-build:
	cd ${WRKSRC}/src/plugins/down-root && ${MAKE}
	cd ${WRKSRC}/src/plugins/auth-pam && ${CC} ${CPPFLAGS} -I../../../include -DDLOPEN_PAM=0 ${CFLAGS} -fPIC -shared -Wl,-soname,openvpn-auth-pam.so -o openvpn-auth-pam.so auth-pam.c pamdl.c -lc -lpam
	@# self-tests here
.if !defined(WITHOUT_CHECK)
	cd ${WRKSRC} && ${MAKE} check
.endif

post-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/plugins/down-root/.libs/openvpn-plugin-down-root.so ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/src/plugins/auth-pam/.libs/openvpn-plugin-auth-pam.so ${PREFIX}/lib/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in AUTHORS COPYING COPYRIGHT.GPL ChangeLog INSTALL \
	PORTS README
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}/
.endfor
.for sample in sample-config-files sample-scripts
	(cd ${WRKSRC}/sample/${sample} && ${COPYTREE_SHARE} \*  ${DOCSDIR}/${sample})
.endfor
.else
	-@${RMDIR} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
