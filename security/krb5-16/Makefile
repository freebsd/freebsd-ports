# Ports collection Makefile for:	MIT Kerberos V
# Version required:			1.0.5
# Date created:				6/5/1998
# Whom:					n@nectar.com
#
# $Id: Makefile,v 1.5 1998/06/23 18:47:00 nectar Exp $
#

DISTNAME=		krb5-1.0.5
CATEGORIES=		security
MASTER_SITES=		ftp://athena-dist.mit.edu/pub/kerberos/
DISTFILES=		krb5-1.0.5.src.tar.gz       \
			krb5-1.0.5.doc.tar.gz       \
			krb5-1.0.5.crypto.tar.gz

MAINTAINER=		n@nectar.com

BUILD_DEPENDS=		gm4:${PORTSDIR}/devel/m4 \
			gmake:${PORTSDIR}/devel/gmake

DIST_SUBDIR=		krb5

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-shared

RESTRICTED=		"Crypto; export-controlled"
# Set USA_RESIDENT appropriately in /etc/make.conf if you like

INFO_FILES=		krb425.info krb5-admin.info krb5-admin.info-1 \
			krb5-admin.info-2 krb5-admin.info-3 krb5-install.info \
			krb5-install.info-1 krb5-install.info-2 krb5-user.info

fetch-depends:
.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != "YES"
	@echo
	@echo ">> You must set the variable USA_RESIDENT to YES if you are"
	@echo "   a United States resident, otherwise NO."
	@echo "   If you are a US resident, understand that this software"
	@echo "   may be export restricted."
	@echo "   If you are not a US resident, then you cannot obtain"
	@echo "   Kerberos V source from a server within the United"
	@echo "   States.  You will have to find the source elsewhere,"
	@echo "   and put them in ${_DISTDIR}."
	@false
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
README_KRB5=		README.KRB5-1.0.5
AWK_SCRIPT=		'/1) Change into the directory/ { if (match($$0, "dist/[0-9]+")) print substr($$0, RSTART, RLENGTH) }'

WANT_HTML?=		YES
HTML_DOC_DIR=		${WRKDIR}/${DISTNAME}/doc
HTML_DOCS=		admin.html install_foot.html user-guide.html          \
			admin_foot.html install_toc.html user-guide_foot.html \
			admin_toc.html krb425.html user-guide_toc.html        \
			install.html krb425_toc.html
SETUID_EXE=		bin/ksu bin/v4rcp

pre-fetch:
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR}; \
	if [ ! -f ${README_KRB5} ]; then \
	for site in ${MASTER_SITES}; do \
		${ECHO_MSG} ">> Attempting to fetch ${README_KRB5} from $${site}."; \
		if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}/${README_KRB5} ${FETCH_AFTER_ARGS}; then \
			break; \
		fi \
	done; fi); \
	if [ ! -f ${_DISTDIR}/${README_KRB5} ]; then \
		${ECHO_MSG} ">> Couldn't fetch it - please try to retrieve"; \
		${ECHO_MSG} ">> this port manually into ${_DISTDIR} and try"; \
		${ECHO_MSG} ">> again."; \
	fi

do-fetch:
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
	@(cd ${WRKSRC}/util/autoconf && ./configure && gmake)
	@(cd ${WRKSRC} && ./util/reconf --force)
	${TOUCH} ${RECONF_COOKIE}

post-build:
	@(cd ${WRKSRC}/../doc && \
	${MAKE} ${INFO_FILES})

post-install:
# XXX Not sure why tmac.doc is installed here -- I don't think
#     we need it.  I should patch the distribution to not install
#     it, I think.
	@rm -f ${PREFIX}/man/man1/tmac.doc
# shared libs
	${LDCONFIG} -m ${PREFIX}/lib
# html documentation
.if defined(WANT_HTML) && ${WANT_HTML} == YES
	@${MKDIR} ${PREFIX}/share/doc/krb5
.for html in ${HTML_DOCS}
	${INSTALL_MAN} ${HTML_DOC_DIR}/${html} ${PREFIX}/share/doc/krb5
.endfor
.endif
# fixup setuid executables
.for setuid in ${SETUID_EXE}
	chown root ${PREFIX}/${setuid}
.endfor
# handle info files
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > \
			${PREFIX}/info/dir; \
	fi
.for info in ${INFO_FILES}
	${INSTALL_MAN} ${WRKSRC}/../doc/${info} ${PREFIX}/info/${info}
.endfor
.for info in ${INFO_FILES:M*.info}
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
