# Ports collection Makefile for:	MIT Kerberos V Application Suite
# Date created:				4/19/2010
# Whom:					cy@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		krb5-appl
PORTVERSION=		1.0.2
PORTREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/${PORTNAME}/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
PATCH_SITES=		http://web.mit.edu/kerberos/advisories/
DISTNAME=		${PORTNAME}-${PORTVERSION}-signed
EXTRACT_SUFX=		.tar
PATCHFILES=		2011-008-patch.txt

MAINTAINER=		cy@FreeBSD.org
COMMENT=		An authentication system developed at MIT, successor to Kerberos IV

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4 \
			krb5-config:${PORTSDIR}/security/krb5
LIB_DEPENDS=		krb5support.0:${PORTSDIR}/security/krb5
RUN_DEPENDS=		kinit:${PORTSDIR}/security/krb5

CONFLICTS=		krb4-[0-9]* krb5-1.[0-7].* heimdal-[0-9]* srp-[0-9]*

LATEST_LINK=		${PORTNAME}-1
KERBEROSV_URL=		http://web.mit.edu/kerberos/
USE_OPENSSL=		yes
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_LDCONFIG=		yes
USE_CSTD=		gnu89
USE_AUTOTOOLS=		libtool autoheader autoconf
CONFIGURE_ARGS?=	--enable-shared --with-krb5=${PREFIX}/bin/krb5-config
CONFIGURE_ENV=		INSTALL="${INSTALL}" YACC=/usr/bin/yacc
MAKE_ARGS=		INSTALL="${INSTALL}"
PATCH_DIST_STRIP=	-p1

OPTIONS=		KRB5_RENAME_FTP "Rename ftp to kftp" off \
			KRB5_RENAME_TELNET "Rename telnet to ktelnet" off \
			KRB5_RENAME_RLOGIN "Rename rlogin to krlogin" off \
			KRB5_RENAME_RSH "Rename rsh to krsh" off \
			KRB5_RENAME_RCP "Rename rcp to krcp" off

.include <bsd.port.pre.mk>

.if defined(WITH_KRB5_DOC)
BUILD_DEPENDS+=		texi2dvi:${PORTSDIR}/print/texinfo \
			dvips:${PORTSDIR}/print/dvipsk-tetex
INFO=			krb5-admin krb5-install krb5-user
.endif

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
.endif

CFLAGS+=		-I${PREFIX}/include
LDFLAGS+=		-L${PREFIX}/lib

MAN1=			rsh.1 rcp.1 rlogin.1 ftp.1 telnet.1
MAN8=			kshd.8 klogind.8 login.krb5.8 ftpd.8 telnetd.8

.if defined(WITH_KRB5_RENAME_FTP)
MAN1:=			${MAN1:C/ftp/kftp/}
MAN8:=			${MAN8:C/ftp/kftp/}
PROGRAM_TRANSFORM_NAME+=	s/^ftp/kftp/;
PLIST_SUB+=		FTP_PROG="kftp"
.else
PLIST_SUB+=		FTP_PROG="ftp"
.endif

.if defined(WITH_KRB5_RENAME_TELNET)
MAN1:=			${MAN1:C/telnet/ktelnet/}
MAN8:=			${MAN8:C/telnet/ktelnet/}
PROGRAM_TRANSFORM_NAME+=	s/^telnet/ktelnet/;
PLIST_SUB+=		TELNET_PROG="ktelnet"
.else
PLIST_SUB+=		TELNET_PROG="telnet"
.endif

.if defined(WITH_KRB5_RENAME_RLOGIN)
MAN1:=			${MAN1:C/rlogin/krlogin/}
PROGRAM_TRANSFORM_NAME+=	s/^rlogin/krlogin/;
PLIST_SUB+=		RLOGIN_PROG="krlogin"
.else
PLIST_SUB+=		RLOGIN_PROG="rlogin"
.endif

.if defined(WITH_KRB5_RENAME_RSH)
MAN1:=			${MAN1:C/rsh/krsh/}
PROGRAM_TRANSFORM_NAME+=	s/^rsh/krsh/;
PLIST_SUB+=		RSH_PROG="krsh"
.else
PLIST_SUB+=		RSH_PROG="rsh"
.endif

.if defined(WITH_KRB5_RENAME_RCP)
MAN1:=			${MAN1:C/rcp/krcp/}
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
	@${TAR} -C ${WRKDIR} -xzf ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz
	@${RM} ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz ${WRKDIR}/${PORTNAME}-${PORTVERSION}.tar.gz.asc
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ `id -u` = 0 ]; then \
		${CHMOD} -R ug-s,go-w ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
		${CHOWN} -R 0:0 ${WRKDIR}/${PORTNAME}-${PORTVERSION}; \
	fi
.endif

post-install:
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
