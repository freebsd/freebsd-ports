# New ports collection makefile for:	openscep
# Date created:		May 19 2005
# Whom:			Vsevolod Stakhov
#
# $FreeBSD$
#

PORTNAME=	openscep
PORTVERSION=	0.4.2
CATEGORIES=	security
MASTER_SITES=	http://openscep.othello.ch/download/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Open source scep server

USE_REINPLACE=	yes
USE_OPENSSL=	yes
USE_OPENLDAP=	yes
USE_APACHE=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-html-install-dir="${PREFIX}/www/openscep" \
		--with-cgi-install-dir="${PREFIX}/www/cgi-bin/openscep" \
		--with-openscep-dir="${PREFIX}/etc/openscep" \
		--with-pkiclientexe="${PREFIX}/www/cgi-bin/pkiclient.exe"

MAKE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

CONF_DIR=	${PREFIX}/etc/${PORTNAME}
CONF_FILES=	openscep.cnf openscep.ldif openscep.schema slapd.conf

SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	CONF_DIR="${CONF_DIR}" CONF_FILES="${CONF_FILES}"

MAN1=		derdump.1 \
		scep.1 \
		scepclient.1 \
		scepconf.1 \
		sceplist.1 \
		scepxid.1
MAN5=		openscep.cnf.5
MAN8=		cafingerprint.8 \
		createcrl.8 \
		crl2ldap.8 \
		dn2xid.8 \
		scepd.8 \
		scepgrant.8 \
		scepreject.8 \
		updatecrl.8

post-patch:
	@${REINPLACE_CMD} -e '/^subdirs=/ s|libltdl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS =/ s|libltdl||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(install-data-am:\) install-data-local$$|\1|' \
		${WRKSRC}/ldap/Makefile.in ${WRKSRC}/openssl/Makefile.in

post-install:
	${MKDIR} ${CONF_DIR}
	${INSTALL_DATA} ${WRKSRC}/openssl/openscep.cnf ${CONF_DIR}/openscep.cnf.default
.for f in openscep.ldif openscep.schema slapd.conf
	${INSTALL_DATA} ${WRKSRC}/ldap/${f} ${CONF_DIR}/${f}.default
.endfor
	${CHOWN} www:www ${PREFIX}/www/cgi-bin/openscep/*
	${CHOWN} www:www ${PREFIX}/www/cgi-bin/pkiclient.exe
	${CHOWN} www:www ${PREFIX}/etc/openscep/*
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
