# Ports collection Makefile for:	MIT Kerberos V
# Version required:			1.0.5
# Date created:				6/5/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=		krb5-1.0.6
CATEGORIES=		security
MASTER_SITES=		# empty here.  See below for real setting.
DISTFILES=		krb5-1.0.6.src.tar.gz       \
			krb5-1.0.6.doc.tar.gz       \
			krb5-1.0.6.crypto.tar.gz

MAINTAINER=		nectar@FreeBSD.org

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4

DIST_SUBDIR=		krb5

# Deal with "secret" subdirectory on the canonical MASTER_SITE.
# If USA_RESIDENT=YES then:
#	we fetch from the canonical MASTER_SITE in the USA,
#	and deal with a "secret" subdirectory whose name
#	we obtain by using an awk script to search a README file.
# If USA_RESIDENT=NO then:
#	we fetch from a MASTER_SITE outside the USA,
#	and we don't need to deal with any "secret" subdirectory,
#	so we use an empty awk script.
README_KRB5=		README.KRB5-1.0.6
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == "YES"
MASTER_SITES=		ftp://athena-dist.mit.edu/pub/kerberos/
AWK_SCRIPT=		'(/1\) Change into the directory/) { if (match($$0, "dist/[0-9]+")) print substr($$0, RSTART, RLENGTH) }'
.else
MASTER_SITES=		ftp://ftp.internat.freebsd.org/pub/FreeBSD/distfiles/
AWK_SCRIPT=		''
.endif

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS?=	--enable-shared --with-ccopts="${CFLAGS}"
KRB5_KRB4_COMPAT?=	YES

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

pre-fetch:
.if !defined(KRB5_KRB4_COMPAT)
	@${ECHO} "------------------------------------------------------"
	@${ECHO} "Set KRB5_KRB4_COMPAT=NO if you do not want to build   "
	@${ECHO} "the KerberosIV compatibility libraries.               "
	@${ECHO} "------------------------------------------------------"
.endif
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == "YES"
	@${ECHO}
	@${ECHO} ">> If you are a US resident, understand that this software"
	@${ECHO} "   may be export restricted."
.elif defined(USA_RESIDENT) && ${USA_RESIDENT} == "NO"
	@${ECHO}
	@${ECHO} ">> If you are not a US resident, then you cannot obtain"
	@${ECHO} "   Kerberos V source from a server within the United"
	@${ECHO} "   States.  If automatic fetching of the sources from"
	@${ECHO} "   a server outside the US fails then you will have to"
	@${ECHO} "   find the sources elsewhere yourself, and put them"
	@${ECHO} "   in ${_DISTDIR}."
.else
	@${ECHO}
	@${ECHO} ">> You must set the variable USA_RESIDENT to YES if you are"
	@${ECHO} "   a United States resident, otherwise NO."
	@${ECHO} "   If you are a US resident, understand that this software"
	@${ECHO} "   may be export restricted."
	@${ECHO} "   If you are not a US resident, then you cannot obtain"
	@${ECHO} "   Kerberos V source from a server within the United"
	@${ECHO} "   States."
	@${FALSE}
.endif

MAN1=			krb5-send-pr.1 kpasswd.1 v5passwd.1 klist.1 kinit.1 \
			kdestroy.1 ksu.1 sclient.1 rsh.1 rcp.1 rlogin.1     \
			v4rcp.1 ftp.1 telnet.1 kerberos.1
MAN5=			kdc.conf.5 krb5.conf.5 .k5login.5
MAN8=			krb5kdc.8 kadmin.8 kadmin.local.8 kdb5_util.8 \
			ktutil.8 kadmind.8 kprop.8 kpropd.8 sserver.8 \
			kshd.8 klogind.8 login.krb5.8 ftpd.8 telnetd.8

WRKSRC=			${WRKDIR}/${DISTNAME}/src
RECONF_COOKIE=		${WRKDIR}/.reconf_done

WANT_HTML?=		YES
HTML_DOC_DIR=		${WRKDIR}/${DISTNAME}/doc
HTML_DOCS=		admin.html install_foot.html user-guide.html          \
			admin_foot.html install_toc.html user-guide_foot.html \
			admin_toc.html krb425.html user-guide_toc.html        \
			install.html krb425_toc.html
SETUID_EXE=		bin/ksu bin/v4rcp

SUPERUSER?=	root

.include <bsd.port.pre.mk>

do-fetch:
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR};                 \
	if [ ! -f ${README_KRB5} ]; then  \
	for site in ${MASTER_SITES}; do   \
		${ECHO_MSG} ">> Attempting to fetch ${README_KRB5} from $${site}."; \
		if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}/${README_KRB5} \
			${FETCH_AFTER_ARGS}; then \
			break;                    \
		fi                                \
	done; fi; ${DO_NADA})
	@(if [ ! -f ${_DISTDIR}/${README_KRB5} ]; then \
		${ECHO_MSG} ">> Couldn't fetch it - please try to retrieve";  \
		${ECHO_MSG} ">> this port manually into ${_DISTDIR} and try"; \
		${ECHO_MSG} ">> again."; \
		${FALSE};                \
	fi)
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR}; \
	 secret=`${AWK} ${AWK_SCRIPT} < ${_DISTDIR}/${README_KRB5}`; \
	 for file in ${DISTFILES}; do \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			if [ -h $$file -o -h `${BASENAME} $$file` ]; then \
				${ECHO_MSG} ">> ${_DISTDIR}/$$file is a broken symlink."; \
				${ECHO_MSG} ">> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
				${ECHO_MSG} ">> Please correct this problem and try again."; \
				exit 1; \
			fi ; \
			${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
			for site in ${MASTER_SITES}; do \
			    ${ECHO_MSG} ">> Attempting to fetch from $${site}/$${secret}."; \
				if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}/$${secret}/$${file} ${FETCH_AFTER_ARGS}; then \
					continue 2; \
				fi \
			done; \
			${ECHO_MSG} ">> Couldn't fetch it - please try to retrieve this";\
			${ECHO_MSG} ">> port manually into ${_DISTDIR} and try again."; \
			exit 1; \
	    fi \
	 done)

pre-configure: ${RECONF_COOKIE}

${RECONF_COOKIE}:
	${SETENV} PORTOBJFORMAT="${PORTOBJFORMAT}" \
	${SH} -c 'cd ${WRKSRC}/util/autoconf && ./configure && ${GMAKE} && cd ${WRKSRC} && ./util/reconf --force'
	${TOUCH} ${RECONF_COOKIE}

post-build:
	@(cd ${WRKSRC}/../doc && \
	${MAKE} ${INFO_FILES})

post-install:
# XXX Not sure why tmac.doc is installed here -- I don't think
#     we need it.  I should patch the distribution to not install
#     it, I think.
	@${RM} -f ${PREFIX}/man/man1/tmac.doc
# shared libs
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
# html documentation
.if defined(WANT_HTML) && ${WANT_HTML} == "YES"
	@${MKDIR} ${PREFIX}/share/doc/krb5
.for html in ${HTML_DOCS}
	${INSTALL_MAN} ${HTML_DOC_DIR}/${html} ${PREFIX}/share/doc/krb5
.endfor
.endif
# fixup setuid executables
.for setuid in ${SETUID_EXE}
	${CHOWN} ${SUPERUSER} ${PREFIX}/${setuid}
.endfor
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

.include <bsd.port.post.mk>

# XXX deal with these patches:
# patch-aw
