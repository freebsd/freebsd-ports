# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=		krb5-maint
PORTVERSION=		1.11.3
PORTREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/${PORTNAME}/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
DISTNAME=		krb5-${PORTVERSION}-signed
EXTRACT_SUFX=		.tar

PATCH_SITES=		http://web.mit.edu/kerberos/advisories/
PATCH_DIST_STRIP=	-p2

MAINTAINER=		cy@FreeBSD.org
COMMENT=		Authentication system developed at MIT, successor to Kerberos IV

LICENSE=		MIT

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4

CONFLICTS=		heimdal-[0-9]* srp-[0-9]* krb5-[0-9]*

LATEST_LINK=		${PORTNAME}-19
KERBEROSV_URL=		http://web.mit.edu/kerberos/
USE_PERL5=		build
USE_LDCONFIG=		yes
USE_CSTD=		gnu99
USE_AUTOTOOLS=		libtool
USES=		gettext gmake perl5
CONFIGURE_ARGS?=	--enable-shared --without-system-verto
CONFIGURE_ENV=		INSTALL="${INSTALL}" YACC="${YACC}"
MAKE_ARGS=		INSTALL="${INSTALL}"

OPTIONS_DEFINE=		KRB5_PDF KRB5_HTML DNS_FOR_REALM LDAP
OPTIONS_DEFAULT=	KRB5_PDF KRB5_HTML
KRB5_PDF_DESC=		Install krb5 PDF documentation
KRB5_HTML_DESC=		Install krb5 HTML documentation
DNS_FOR_REALM_DESC=	Enable DNS lookups for Kerberos realm names
LDAP=			Enable LDAP support

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
CFLAGS+=		-rpath=${KRB5_HOME}/lib
LDFLAGS+=		-rpath=${KRB5_HOME}/lib
.endif
LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${LOCALBASE}/include

USE_OPENSSL=		yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDNS_FOR_REALM}
CONFIGURE_ARGS+=	--enable-dns-for-realm
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
PLIST_SUB+=		LDAP=""
.else
PLIST_SUB+=		LDAP="@comment "
.endif

.include "${PORTSDIR}/Mk/bsd.openssl.mk"

MAN1=			k5srvutil.1 kadmin.1 krb5-config.1 krb5-send-pr.1 \
			kpasswd.1 klist.1 kinit.1 kdestroy.1 kswitch.1 ksu.1 \
			ktutil.1 \
			sclient.1 kvno.1 compile_et.1
MAN5=			kadm5.acl.5 kdc.conf.5 krb5.conf.5 .k5identity.5 \
			.k5login.5 k5identity.5 k5login.5
MAN8=			krb5kdc.8 kadmin.local.8 kdb5_ldap_util.8 kdb5_util.8 \
			kadmind.8 kprop.8 kpropd.8 kproplog.8 sserver.8

.if defined(PROGRAM_TRANSFORM_NAME) && ${PROGRAM_TRANSFORM_NAME} != ""
CONFIGURE_ARGS+=	--program-transform-name="${PROGRAM_TRANSFORM_NAME}"
.endif

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

HTML_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/html
PDF_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/pdf

CONFIGURE_ARGS+=	CPPFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB} -L${LOCALBASE}/include"

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz
	@${RM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz.asc
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ `id -u` = 0 ]; then \
		${CHMOD} -R ug-s,go-w ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
		${CHOWN} -R 0:0 ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
	fi
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/doc/krb5
# html documentation
.if ${PORT_OPTIONS:MKRB5_PDF}
	pdf_files=`${FIND} ${PDF_DOC_DIR} ! -type d`
	pdf_dirs=`${FIND} ${PDF_DOC_DIR} -type d`
	for i in $${pdf_dirs}; do \
		${MKDIR} ${PREFIX}/share/doc/krb5/$${i}; \
	done; \
	for i in $${pdf_files}; do \
		${INSTALL_MAN} $${pdf} ${PREFIX}/share/doc/krb5/$${i}; \
		${ECHO_CMD} share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done
.endif
.if ${PORT_OPTIONS:MKRB5_HTML}
	html_files=`${FIND} ${HTML_DOC_DIR} ! -type d | ${GREP} -v /_sources`
	html_dirs=`${FIND} ${HTML_DOC_DIR} -type d | ${GREP} -v /_sources`
	for i in $${html_dirs}; do \
		${MKDIR} ${PREFIX}/share/doc/krb5/$${i}; \
	done; \
	for i in $${html_files}; do \
		${INSTALL_MAN} $${i} ${PREFIX}/share/doc/krb5/$${i}; \
		${ECHO_CMD} share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done
.endif
.if ${PORT_OPTIONS:MKRB5_PDF}
	for i in $${pdf_dirs}; do \
		${ECHO_CMD} @dirrm share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done | ${TAIL} -r >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MKRB5_HTML}
	for i in $${html_dirs}; do \
		${ECHO_CMD} @dirrm share/doc/krb5/$${i} >> ${TMPPLIST}; \
	done | ${TAIL} -r >> ${TMPPLIST}
.endif
	${ECHO_CMD} @dirrm share/doc/krb5 >> ${TMPPLIST}
	@${SED} "s%\${PREFIX}%${PREFIX}%" ${FILESDIR}/README.FreeBSD > ${PREFIX}/share/doc/krb5/README.FreeBSD
	@${CHMOD} 444 ${PREFIX}/share/doc/krb5/README.FreeBSD
	@${ECHO} "------------------------------------------------------"
	@${ECHO} "This port of MIT Kerberos 5 includes remote login     "
	@${ECHO} "daemons (telnetd and klogind).  These daemons default "
	@${ECHO} "to using the system login program (/usr/bin/login).   "
	@${ECHO} "Please see the file                                   "
	@${ECHO} "${PREFIX}/share/doc/krb5/README.FreeBSD"
	@${ECHO} "for more information.                                 "
	@${ECHO} "------------------------------------------------------"

.include <bsd.port.post.mk>
