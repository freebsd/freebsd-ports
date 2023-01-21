PORTNAME=	openscep
PORTVERSION=	0.4.2
PORTREVISION=	11
CATEGORIES=	security
MASTER_SITES=	http://openscep.othello.ch/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source scep server
WWW=		http://openscep.othello.ch/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Do not support recent RFC 8894
EXPIRATION_DATE=	2023-03-31

USES=		apache gmake libtool ssl
BROKEN_SSL=	base
BROKEN_SSL_REASON=	unexpected type name 'issuer_and_subject_t': expected expression
IGNORE_SSL=	libressl libressl-devel
IGNORE_SSL_REASON=	unknown ASN1 functions
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-install-dir="${PREFIX}/www/openscep" \
		--with-cgi-install-dir="${PREFIX}/www/cgi-bin/openscep" \
		--with-openscep-dir="${PREFIX}/etc/openscep" \
		--with-pkiclientexe="${PREFIX}/www/cgi-bin/pkiclient.exe"

CPPFLAGS+=	-I${OPENSSLINC} -I${LOCALBASE}/include
LIBS+=		-L${OPENSSLLIB} -L${LOCALBASE}/lib

CONF_DIR=	${PREFIX}/etc/${PORTNAME}
LOCAL_CONF_FILES=	openscep.cnf openscep.ldif openscep.schema slapd.conf

CONFLICTS_INSTALL=	nss-3.*

SUB_FILES=	pkg-message
SUB_LIST=	CONF_DIR="${CONF_DIR}" CONF_FILES="${LOCAL_CONF_FILES}"

post-patch:
	@${REINPLACE_CMD} -e '/^subdirs=/ s|libltdl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS =/ s|libltdl||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(install-data-am:\) install-data-local$$|\1|' \
		${WRKSRC}/ldap/Makefile.in ${WRKSRC}/openssl/Makefile.in
	@${REINPLACE_CMD} 's,sbindir),DESTDIR)$$(&,' \
		${WRKSRC}/openssl/Makefile.in
	@${REINPLACE_CMD} -E -e 's,(bin|sbin)dir},DESTDIR}$${&,'  \
		-e 's,-o \$$\(USER\) -g \$$\(GROUP\),,' \
		${WRKSRC}/scep/Makefile.in \
		${WRKSRC}/scepd/Makefile.in
	@${REINPLACE_CMD} -E 's,(CGIINSTALLDIR|PKICLIENTEXE)),DESTDIR)$$(&,' \
		${WRKSRC}/cgi-bin/Makefile.in
	@${REINPLACE_CMD} 's|HTMLINSTALLDIR)|DESTDIR)$$(&|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/doc/Makefile.in \
		${WRKSRC}/html/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libscep.so
	@${MKDIR} ${STAGEDIR}${CONF_DIR}
	${INSTALL_DATA} ${WRKSRC}/openssl/openscep.cnf \
		${STAGEDIR}${CONF_DIR}/openscep.cnf.sample
.for f in openscep.ldif openscep.schema slapd.conf
	${INSTALL_DATA} ${WRKSRC}/ldap/${f} ${STAGEDIR}${CONF_DIR}/${f}.sample
.endfor

.include <bsd.port.mk>
