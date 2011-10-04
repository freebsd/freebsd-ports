# New ports collection makefile for:	openvpn
# Date created:		2002-06-23
# Whom:			Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	openvpn
DISTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	security net
# MASTER_SITES points to hosts in distinct data centers,
# so just one MASTER_SITES entry should be OK.
MASTER_SITES=	http://swupdate.openvpn.net/community/releases/ \
		${MASTER_SITE_LOCAL:S,$,mandree/,}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Secure IP/Ethernet tunnel daemon

LICENSE=	GPLv2

CONFLICTS_INSTALL=	openvpn-devel-[0-9]* openvpn-2.0* openvpn-beta-[0-9]*

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_XZ=		yes
CONFIGURE_ARGS=	--with-lzo-lib=${LOCALBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include
.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install
.else
INSTALL_TARGET=	install-exec install-man
.endif

INSTALL_TARGET+=	mandir=${MANPREFIX}/man
MAN8=		openvpn.8

OPTIONS=	PW_SAVE "Interactive passwords may be read from a file" off \
		PKCS11  "Use security/pkcs11-helper" off

USE_RC_SUBR=	openvpn.sh
USE_LDCONFIG=	${PREFIX}/lib

SUB_FILES=	pkg-message
SUB_LIST+=	OSVERSION=${OSVERSION}

.include <bsd.port.pre.mk>

.ifdef (LOG_OPENVPN)
CFLAGS+=	-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

LIB_DEPENDS+=	lzo2.2:${PORTSDIR}/archivers/lzo2

.if defined(WITH_PW_SAVE)
CONFIGURE_ARGS+=	--enable-password-save
.endif

.if defined(WITH_PKCS11)
LIB_DEPENDS+=	pkcs11-helper.1:${PORTSDIR}/security/pkcs11-helper
.else
CONFIGURE_ARGS+=	--disable-pkcs11
.endif

post-extract:
	@${RM} ${WRKSRC}/easy-rsa/2.0/openssl-1.0.0.cnf-old-copy

post-patch:
	@${FIND} ${WRKSRC}/easy-rsa/?.0 -type f \
	    -exec ${REINPLACE_CMD} -e 's;#!/bin/bash;#!/bin/sh;' \
				   -e 's,source ./vars,. ./vars,' \{\} +
	@${FIND} ${WRKSRC}/plugin -name Makefile \
	    -exec ${REINPLACE_CMD} -e 's;gcc;${CC};g' '{}' +
	@${FIND} ${WRKSRC} \( -name \*.orig -o -name \*.bak \) -delete

pre-configure:
.ifdef (LOG_OPENVPN)
	@${ECHO} "Building with LOG_OPENVPN=${LOG_OPENVPN}"
.else
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      LOG_OPENVPN={Valid syslog facility, default LOG_DAEMON}"
	@${ECHO} "      EXAMPLE:  make LOG_OPENVPN=LOG_DAEMON"
	@${ECHO} ""
.endif

post-build:
	cd ${WRKSRC}/plugin/down-root && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS}
	cd ${WRKSRC}/plugin/auth-pam && ${CC} ${CPPFLAGS} -I../.. -DDLOPEN_PAM=0 ${CFLAGS} -fPIC -shared -Wl,-soname,openvpn-auth-pam.so -o openvpn-auth-pam.so auth-pam.c pamdl.c -lc -lpam
	@# self-tests here
.if !defined(WITHOUT_CHECK)
	@${ECHO} ; ${ECHO} "### Note that you can skip these lengthy selftests with WITHOUT_CHECK=yes ###" ; ${ECHO}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} check
.endif

post-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/plugin/down-root/openvpn-down-root.so ${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/plugin/auth-pam/openvpn-auth-pam.so ${PREFIX}/lib/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/plugin/down-root/README ${DOCSDIR}/README.openvpn-down-root
	${INSTALL_DATA} ${WRKSRC}/plugin/auth-pam/README ${DOCSDIR}/README.openvpn-auth-pam
.for docs in AUTHORS COPYING COPYRIGHT.GPL ChangeLog INSTALL \
	PORTS README
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}/
.endfor
.for dir in easy-rsa easy-rsa/1.0 easy-rsa/2.0 sample-config-files
	${MKDIR} ${DOCSDIR}/${dir}
	${FIND} ${WRKSRC}/${dir}/ -maxdepth 1 -type f -exec ${INSTALL_DATA} \{\} ${DOCSDIR}/${dir} \;
.endfor
.for dir in sample-scripts
	${MKDIR} ${DOCSDIR}/${dir}
	${FIND} ${WRKSRC}/${dir}/ -maxdepth 1 -type f -exec ${INSTALL_SCRIPT} \{\} ${DOCSDIR}/${dir} \;
.endfor
.else
	-@${RMDIR} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
