# Created by: Vsevolod Stakhov
# $FreeBSD$

PORTNAME=	openscep
PORTVERSION=	0.4.2
PORTREVISION=	10
CATEGORIES=	security
MASTER_SITES=	http://openscep.othello.ch/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source scep server

CONFLICTS_INSTALL=	nss-3.*

USES=		apache:2.2+ gmake libtool ssl
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${OPENSSLINC} -I${LOCALBASE}/include
LIBS+=		-L${OPENSSLLIB} -L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-html-install-dir="${PREFIX}/www/openscep" \
		--with-cgi-install-dir="${PREFIX}/www/cgi-bin/openscep" \
		--with-openscep-dir="${PREFIX}/etc/openscep" \
		--with-pkiclientexe="${PREFIX}/www/cgi-bin/pkiclient.exe"

CONF_DIR=	${PREFIX}/etc/${PORTNAME}
LOCAL_CONF_FILES=	openscep.cnf openscep.ldif openscep.schema slapd.conf

SUB_FILES=	pkg-message
SUB_LIST=	CONF_DIR="${CONF_DIR}" CONF_FILES="${LOCAL_CONF_FILES}"

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=	Detected LibreSSL (unknown ASN1 functions)
.endif

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

.include <bsd.port.post.mk>
