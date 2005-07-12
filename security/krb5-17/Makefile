# Ports collection Makefile for:	MIT Kerberos V
# Date created:				6/5/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		krb5
PORTVERSION=		1.4.1
PORTREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://web.mit.edu/kerberos/dist/krb5/${PORTVERSION:C/\.[0-9]*$/&/:C/\.[0-9]*$//}/
EXTRACT_SUFX=		.tar
DISTNAME=		${PORTNAME}-${PORTVERSION}-signed

MAINTAINER=		cy@FreeBSD.org
COMMENT=		An authentication system developed at MIT, successor to Kerberos IV

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4

LATEST_LINK=		${PORTNAME}
KERBEROSV_URL=		http://web.mit.edu/kerberos/
USE_REINPLACE=		yes
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS?=	--enable-shared --enable-static
CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ENV=		INSTALL="${INSTALL}" YACC=/usr/bin/yacc \
			CFLAGS="${CFLAGS}"
MAKE_ARGS=		INSTALL="${INSTALL}"
KRB5_KRB4_COMPAT?=	NO

.if !defined(KRB5_KRB4_COMPAT) || ${KRB5_KRB4_COMPAT} == "NO"
CONFIGURE_ARGS+=	--without-krb4
PLIST_SUB+=		KRB4="@comment "
.else
PLIST_SUB+=		KRB4=""
.endif

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
.endif

INFO_FILES=		krb425.info krb5-admin.info krb5-admin.info-1 \
			krb5-admin.info-2 krb5-admin.info-3 krb5-install.info \
			krb5-install.info-1 krb5-install.info-2 krb5-user.info

MAN1=			krb5-send-pr.1 krb5-config.1 kpasswd.1 klist.1 \
			kinit.1 kdestroy.1 ksu.1 sclient.1 rsh.1 rcp.1 \
			rlogin.1 ftp.1 telnet.1 kerberos.1 kvno.1 compile_et.1
.if defined(KRB5_KRB4_COMPAT) && ${KRB5_KRB4_COMPAT} != "NO"
MAN1+=			v4rcp.1
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
HTML_DOCS=		admin.html user-guide.html install.html
HTML_OUTDIRS=		krb5-admin krb5-install

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
	@(cd ${WRKSRC}/../doc && \
	${MAKE} ${INFO_FILES})
.if defined(WANT_HTML) && ${WANT_HTML} == "YES"
	@(cd ${WRKSRC}/../doc && \
	${MAKE} ${HTML_DOCS})
.endif

post-install:
# html documentation
.if defined(WANT_HTML) && ${WANT_HTML} == "YES"
	@${MKDIR} ${PREFIX}/share/doc/krb5
	for html in ${HTML_DOC_DIR}/*.html; do \
		${INSTALL_MAN} $${html} ${PREFIX}/share/doc/krb5; \
		${ECHO_CMD} share/doc/krb5/`${BASENAME} $${html}` >> ${TMPPLIST}; \
	done
.for htmldir in ${HTML_OUTDIRS}
	@${MKDIR} ${PREFIX}/share/doc/krb5/${htmldir}
	for html in ${HTML_DOC_DIR}/${htmldir}/*; do \
		${INSTALL_MAN} $${html} ${PREFIX}/share/doc/krb5/${htmldir}; \
		${ECHO_CMD} share/doc/krb5/${htmldir}/`${BASENAME} $${html}` >> ${TMPPLIST}; \
	done
	${ECHO_CMD} @dirrm share/doc/krb5/${htmldir} >> ${TMPPLIST}
.endfor
.endif
	${ECHO_CMD} @dirrm share/doc/krb5 >> ${TMPPLIST}
# handle info files
.for info in ${INFO_FILES}
	${INSTALL_MAN} ${WRKSRC}/../doc/${info} ${PREFIX}/info/${info}
.endfor
.for info in ${INFO_FILES:M*.info}
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# fixup packing list (no libs without version numbers in aout case)
.if ${PORTOBJFORMAT} == "aout"
	${ECHO_MSG} "Fixing packing list for a.out"
	${MV} ${TMPPLIST} ${TMPPLIST}.new
	${GREP} -v '\.so$$' ${TMPPLIST}.new > ${TMPPLIST}
	${RM} ${TMPPLIST}.new
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
