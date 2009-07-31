# Ports collection Makefile for:	MIT Kerberos V
# Date created:				6/5/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		krb5
PORTVERSION=		1.6.3
PORTREVISION=	6
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/krb5/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
PATCH_SITES=		http://web.mit.edu/kerberos/advisories/
DISTNAME=		${PORTNAME}-${PORTVERSION}-signed
EXTRACT_SUFX=		.tar
PATCHFILES=		2008-001-patch.txt
PATCH_DIST_STRIP=	-p1

MAINTAINER=		cy@FreeBSD.org
COMMENT=		An authentication system developed at MIT, successor to Kerberos IV

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4

CONFLICTS=		krb4-[0-9]* heimdal-[0-9]* srp-[0-9]*

LATEST_LINK=		${PORTNAME}
KERBEROSV_URL=		http://web.mit.edu/kerberos/
USE_OPENSSL=		yes
WITH_OPENSSL_PORT=	yes
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_LDCONFIG=		yes
USE_AUTOTOOLS=		libtool:15
CONFIGURE_ARGS?=	--enable-shared
# CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ENV=		INSTALL="${INSTALL}" YACC=/usr/bin/yacc \
			CFLAGS="${CFLAGS}"
MAKE_ARGS=		INSTALL="${INSTALL}"

OPTIONS=		KRB5_RENAME_FTP "Rename ftp to kftp" off \
			KRB5_RENAME_TELNET "Rename telnet to ktelnet" off \
			KRB5_RENAME_RLOGIN "Rename rlogin to krlogin" off \
			KRB5_RENAME_RSH "Rename rsh to krsh" off \
			KRB5_RENAME_RCP "Rename rcp to krcp" off \
			KRB5_KRB4_COMPAT "Build and install krb4 compatibility" off \
			KRB5_DOC "Build and install krb5 documentation" on \
			WANT_HTML "Want HTML documentation too" on

.include <bsd.port.pre.mk>

.if defined(WITH_KRB5_DOC)
BUILD_DEPENDS+=		texi2dvi:${PORTSDIR}/print/texinfo \
			dvips:${PORTSDIR}/print/dvipsk-tetex
INFO=			krb425 krb5-admin krb5-install krb5-user
.endif

.if !defined(WITH_KRB5_KRB4_COMPAT)
CONFIGURE_ARGS+=	--without-krb4
PLIST_SUB+=		KRB4="@comment "
.else
PLIST_SUB+=		KRB4=""
.endif

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
.endif

MAN1=			krb5-send-pr.1 krb5-config.1 kpasswd.1 klist.1 \
			kinit.1 kdestroy.1 ksu.1 sclient.1 rsh.1 rcp.1 \
			rlogin.1 ftp.1 telnet.1 kerberos.1 kvno.1 compile_et.1
MAN5=			kdc.conf.5 krb5.conf.5 .k5login.5
MAN8=			krb5kdc.8 kadmin.8 kadmin.local.8 kdb5_util.8 \
			ktutil.8 kadmind.8 kprop.8 kpropd.8 sserver.8 \
			kshd.8 klogind.8 login.krb5.8 ftpd.8 telnetd.8 \
			k5srvutil.8
.if defined(WITH_KRB5_KRB4_COMPAT)
MAN8+=			krb524d.8
.endif

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

.if defined(WITH_KRB5_KRB4_COMPAT)
MAN1+=			krb524init.1 v4rcp.1
.endif

.if defined(PROGRAM_TRANSFORM_NAME) && ${PROGRAM_TRANSFORM_NAME} != ""
CONFIGURE_ARGS+=	--program-transform-name="${PROGRAM_TRANSFORM_NAME}"
.endif

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

HTML_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc
HTML_DOCS=		ftp.html kdestroy.html kinit.html klist.html \
			kpasswd.html krb425.html krb5-admin.html \
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

post-patch:
	@${REINPLACE_CMD} -e '1s,^#!\/usr\/athena/bin/perl,#!${PERL5},' \
		${WRKSRC}/../doc/man2html

pre-build:
.if !defined(KRB5_KRB4_COMPAT)
	@${ECHO} "------------------------------------------------------"
	@${ECHO} "Set KRB5_KRB4_COMPAT=NO if you do not want to build   "
	@${ECHO} "the KerberosIV compatibility libraries.               "
	@${ECHO} "------------------------------------------------------"
.endif

post-build:
.if defined(WITH_KRB5_DOC)
	@cd ${WRKSRC}/../doc && \
	${MAKE} all
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/doc/krb5
# html documentation
.if defined(WITH_KRB5_DOC) && defined(WITH_WANT_HTML)
	for html in ${HTML_DOC_DIR}/*.html; do \
		${INSTALL_MAN} $${html} ${PREFIX}/share/doc/krb5; \
		${ECHO_CMD} share/doc/krb5/`${BASENAME} $${html}` >> ${TMPPLIST}; \
	done
.endif
	${ECHO_CMD} @dirrm share/doc/krb5 >> ${TMPPLIST}
# handle info files
.if defined(WITH_KRB5_DOC)
.for info in ${INFO}
	${INSTALL_MAN} ${WRKSRC}/../doc/${info}.info ${PREFIX}/info/${info}.info
.endfor
.endif

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
