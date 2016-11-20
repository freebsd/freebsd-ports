# Created by: cy@FreeBSD.org
# $FreeBSD$

PORTNAME=		krb5-appl
PORTVERSION=		1.0.3
PORTREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/${PORTNAME}/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
DISTNAME=		${PORTNAME}-${PORTVERSION}-signed
EXTRACT_SUFX=		.tar

PATCH_SITES=		http://web.mit.edu/kerberos/advisories/

MAINTAINER=		cy@FreeBSD.org
COMMENT=		Authentication system developed at MIT, successor to Kerberos IV

BUILD_DEPENDS=		krb5-config:security/krb5

CONFLICTS=		krb4-[0-9]* krb5-1.[0-7].* heimdal-[0-9]* srp-[0-9]*

KERBEROSV_URL=		http://web.mit.edu/kerberos/
USES=			autoreconf gmake ncurses perl5 gssapi:mit ssl
GNU_CONFIGURE=		yes
USE_PERL5=		build
USE_LDCONFIG=		yes
USE_CSTD=		gnu89
CONFIGURE_ARGS?=	--enable-shared --with-krb5=${PREFIX}/bin/krb5-config
CONFIGURE_ENV=		INSTALL="${INSTALL}" YACC=/usr/bin/yacc
MAKE_ARGS=		INSTALL="${INSTALL}"
PATCH_DIST_STRIP=	-p1

OPTIONS_DEFINE=	KRB5_RENAME_FTP KRB5_RENAME_TELNET KRB5_RENAME_RLOGIN KRB5_RENAME_RSH KRB5_RENAME_RCP
OPTIONS_DEFAULT=	KRB5_PORT
OPTIONS_SINGLE=		KRB5_VERSION
OPTIONS_SINGLE_KRB5_VERSION=	KRB5_PORT KRB5_113_PORT \
			KRB5_114_PORT
KRB5_RENAME_FTP_DESC=		Rename ftp to kftp
KRB5_RENAME_TELNET_DESC=	Rename telnet to ktelnet
KRB5_RENAME_RLOGIN_DESC=	Rename rlogin to krlogin
KRB5_RENAME_RSH_DESC=		Rename rsh to krsh
KRB5_RENAME_RCP_DESC=		Rename rcp to krcp
KRB5_PORT_DESC=			Depend on security/krb5
KRB5_113_PORT_DESC=		Depend on security/krb5-113
KRB5_114_PORT_DESC=		Depend on security/krb5-114

.include <bsd.port.pre.mk>

KRB5_PORT_LIB_DEPENDS=		libkrb5support.so:security/krb5
KRB5_PORT_RUN_DEPENDS=		kinit:security/krb5
KRB5_113_PORT_LIB_DEPENDS=		libkrb5support.so:security/krb5-113
KRB5_113_PORT_RUN_DEPENDS=		kinit:security/krb5-113
KRB5_114_PORT_LIB_DEPENDS=		libkrb5support.so:security/krb5-114
KRB5_114_PORT_RUN_DEPENDS=		kinit:security/krb5-113

KRB5_DOC_BUILD_DEPENDS+=	texi2dvi:print/texinfo \
			dvips:print/dvipsk-tetex
KRB5_DOC_INFO=			krb5-admin krb5-install krb5-user

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
.if ${KRB5_HOME} != ${LOCALBASE}
BROKEN=			LIB_DEPENDS when using KRB5_HOME is broken
.endif
.endif

CFLAGS+=		-I${PREFIX}/include
LDFLAGS+=		-L${PREFIX}/lib

.if ${PORT_OPTIONS:MKRB5_RENAME_FTP}
PROGRAM_TRANSFORM_NAME+=	s/^ftp/kftp/;
PLIST_SUB+=		FTP_PROG="kftp"
.else
PLIST_SUB+=		FTP_PROG="ftp"
.endif

.if ${PORT_OPTIONS:MKRB5_RENAME_TELNET}
PROGRAM_TRANSFORM_NAME+=	s/^telnet/ktelnet/;
PLIST_SUB+=		TELNET_PROG="ktelnet"
.else
PLIST_SUB+=		TELNET_PROG="telnet"
.endif

.if ${PORT_OPTIONS:MKRB5_RENAME_RLOGIN}
PLIST_SUB+=		RLOGIN_PROG="krlogin"
PROGRAM_TRANSFORM_NAME+=	s/^rlogin/krlogin/;
.else
PLIST_SUB+=		RLOGIN_PROG="rlogin"
.endif

.if ${PORT_OPTIONS:MKRB5_RENAME_RSH}
PLIST_SUB+=		RSH_PROG="krsh"
PROGRAM_TRANSFORM_NAME+=	s/^rsh/krsh/;
.else
PLIST_SUB+=		RSH_PROG="rsh"
.endif

.if ${PORT_OPTIONS:MKRB5_RENAME_RCP}
PROGRAM_TRANSFORM_NAME+=	s/^rcp/krcp/;
PLIST_SUB+=		RCP_PROG="krcp"
.else
PLIST_SUB+=		RCP_PROG="rcp"
.endif

.if defined(PROGRAM_TRANSFORM_NAME) && ${PROGRAM_TRANSFORM_NAME} != ""
CONFIGURE_ARGS+=	--program-transform-name="${PROGRAM_TRANSFORM_NAME}"
.endif

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

HTML_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc
HTML_DOCS=		ftp.html kdestroy.html kinit.html klist.html \
			kpasswd.html krb5-admin.html \
			krb5-install.html krb5-user.html ksu.html \
			rcp.html rlogin.html rsh.html telnet.html

CONFIGURE_ARGS+=	CPPFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}"

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz --no-same-owner --no-same-permissions
	@${RM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz.asc

post-install:
	@${ECHO} "------------------------------------------------------"
	@${ECHO} "This port of MIT Kerberos 5 includes remote login     "
	@${ECHO} "daemons (telnetd and klogind).  These daemons default "
	@${ECHO} "to using the system login program (/usr/bin/login).   "
	@${ECHO} "Please see the file                                   "
	@${ECHO} "${PREFIX}/share/doc/krb5/README.FreeBSD"
	@${ECHO} "for more information.                                 "
	@${ECHO} "------------------------------------------------------"

.include <bsd.port.post.mk>
