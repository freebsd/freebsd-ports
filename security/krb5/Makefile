# Ports collection Makefile for:	MIT Kerberos V
# Date created:				6/5/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		krb5
PORTVERSION=		1.2.3
CATEGORIES=		security
MASTER_SITES=		# manual download

MAINTAINER=		cy@FreeBSD.org

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4

KERBEROSV_URL=		http://web.mit.edu/network/kerberos-form.html
USE_GMAKE=		yes
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS?=	--enable-shared --with-ccopts="${CFLAGS}"
CONFIGURE_ENV=		INSTALL="${INSTALL}"
MAKE_ARGS=		INSTALL="${INSTALL}"
KRB5_KRB4_COMPAT?=	YES

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == "NO"
MASTER_SITES=          http://www.crypto-publish.org/dist/mit-kerberos5/
.endif

.if !defined(KRB5_KRB4_COMPAT) || ${KRB5_KRB4_COMPAT} == "NO"
CONFIGURE_ARGS+=	--without-krb4
.endif

.if defined(KRB5_HOME)
PREFIX=			${KRB5_HOME}
.endif

RESTRICTED=		"Crypto; export-controlled"
# Set USA_RESIDENT appropriately in /etc/make.conf if you like

INFO_FILES=		krb425.info krb5-admin.info krb5-admin.info-1 \
			krb5-admin.info-2 krb5-admin.info-3 krb5-install.info \
			krb5-install.info-1 krb5-install.info-2 krb5-user.info

MAN1=			krb5-send-pr.1 kpasswd.1 v5passwd.1 klist.1 kinit.1 \
			kdestroy.1 ksu.1 sclient.1 rsh.1 rcp.1 rlogin.1     \
			v4rcp.1 ftp.1 telnet.1 kerberos.1 kvno.1
MAN5=			kdc.conf.5 krb5.conf.5 .k5login.5
MAN8=			krb5kdc.8 kadmin.8 kadmin.local.8 kdb5_util.8 \
			ktutil.8 kadmind.8 kprop.8 kpropd.8 sserver.8 \
			kshd.8 klogind.8 login.krb5.8 ftpd.8 telnetd.8

WRKSRC=			${WRKDIR}/${DISTNAME}/src

WANT_HTML?=		YES
HTML_DOC_DIR=		${WRKDIR}/${DISTNAME}/doc
HTML_DOCS=		admin.html install_foot.html user-guide.html          \
			admin_foot.html install_toc.html user-guide_foot.html \
			admin_toc.html krb425.html user-guide_toc.html        \
			install.html krb425_toc.html

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} == "YES"
do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then        \
	${ECHO} "";							\
	${ECHO} ">> Kerberos V contains encryption software and is";    \
	${ECHO} "   export restricted.  If you are not a USA resident,";\
	${ECHO} "   then you cannot obtain the Kerberos V sources from";\
	${ECHO} "   within the United States.";                         \
	${ECHO} "";							\
	${ECHO} ">> The Kerberos V sources must be fetched manually.";  \
	${ECHO} "   Please visit ${KERBEROSV_URL}";                     \
	${ECHO} "   to download ${DISTNAME}${EXTRACT_SUFX} and place";  \
	${ECHO} "   it in ${DISTDIR}.  Then run make again.";           \
	${FALSE};							\
	fi
.endif

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

.include <bsd.port.pre.mk>

post-install:
# html documentation
.if defined(WANT_HTML) && ${WANT_HTML} == "YES"
	@${MKDIR} ${PREFIX}/share/doc/krb5
.for html in ${HTML_DOCS}
	${INSTALL_MAN} ${HTML_DOC_DIR}/${html} ${PREFIX}/share/doc/krb5
.endfor
.endif
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
	@${SED} "s%\${PREFIX}%${PREFIX}%" ${FILESDIR} > ${PREFIX}/share/doc/krb5/README.FreeBSD
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
