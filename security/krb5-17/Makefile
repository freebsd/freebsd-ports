# Ports collection Makefile for:	MIT Kerberos V
# Date created:				6/5/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		krb5
PORTVERSION=		1.6
PORTREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/krb5/${PORTVERSION:C/^[0-9]*\.[0-9]*/&X/:C/X\.[0-9]*$//:C/X//}/
DISTNAME=		${PORTNAME}-${PORTVERSION}-signed
EXTRACT_SUFX=		.tar

MAINTAINER=		cy@FreeBSD.org
COMMENT=		An authentication system developed at MIT, successor to Kerberos IV

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4

CONFLICTS=		krb4-[0-9]* heimdal-[0-9]* srp-[0-9]*

LATEST_LINK=		${PORTNAME}
KERBEROSV_URL=		http://web.mit.edu/kerberos/
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_LDCONFIG=		yes
USE_AUTOTOOLS=		libtool:15
CONFIGURE_ARGS?=	--enable-shared
# CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ENV=		INSTALL="${INSTALL}" YACC=/usr/bin/yacc \
			CFLAGS="${CFLAGS}"
MAKE_ARGS=		INSTALL="${INSTALL}"
KRB5_KRB4_COMPAT?=	NO
KRB5_DOC?=		YES

.if defined(KRB5_DOC) && ${KRB5_DOC} == "YES"
BUILD_DEPENDS+=		texi2dvi:${PORTSDIR}/print/texinfo \
			dvips:${PORTSDIR}/print/dvipsk-tetex
INFO=			krb425 krb5-admin krb5-install krb5-user
.endif

.if !defined(KRB5_KRB4_COMPAT) || ${KRB5_KRB4_COMPAT} == "NO"
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
.if defined(KRB5_KRB4_COMPAT) && ${KRB5_KRB4_COMPAT} != "NO"
MAN1+=			krb524init.1 v4rcp.1
.endif
MAN5=			kdc.conf.5 krb5.conf.5 .k5login.5
MAN8=			krb5kdc.8 kadmin.8 kadmin.local.8 kdb5_util.8 \
			ktutil.8 kadmind.8 kprop.8 kpropd.8 sserver.8 \
			kshd.8 klogind.8 login.krb5.8 ftpd.8 telnetd.8 \
			k5srvutil.8
.if defined(KRB5_KRB4_COMPAT) && ${KRB5_KRB4_COMPAT} != "NO"
MAN8+=			krb524d.8
.endif

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

WANT_HTML?=		YES
HTML_DOC_DIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc
HTML_DOCS=		ftp.html kdestroy.html kinit.html klist.html \
			kpasswd.html krb425.html krb5-admin.html \
			krb5-install.html krb5-user.html ksu.html \
			rcp.html rlogin.html rsh.html telnet.html


.include <bsd.port.pre.mk>

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
.if defined(KRB5_DOC) && ${KRB5_DOC} == "YES"
	@cd ${WRKSRC}/../doc && \
	${MAKE} all
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/doc/krb5
# html documentation
.if defined(KRB5_DOC) && ${KRB5_DOC} == "YES" && defined(WANT_HTML) && ${WANT_HTML} == "YES"
	for html in ${HTML_DOC_DIR}/*.html; do \
		${INSTALL_MAN} $${html} ${PREFIX}/share/doc/krb5; \
		${ECHO_CMD} share/doc/krb5/`${BASENAME} $${html}` >> ${TMPPLIST}; \
	done
.endif
	${ECHO_CMD} @dirrm share/doc/krb5 >> ${TMPPLIST}
# handle info files
.if defined(KRB5_DOC) && ${KRB5_DOC} == "YES"
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
