# Created by: n_hibma@qubesoft.com
# $FreeBSD$

PORTNAME=	mailman
DISTVERSION=	2.1.26
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	GNU \
		SF/${PORTNAME}/Mailman%202.1%20%28stable%29/${PORTVERSION} \
		https://launchpad.net/mailman/${DISTVERSION:R}/${DISTVERSION}/+download/
DIST_SUBDIR=	mailman

PATCH_SITES=	LOCAL/mandree
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Mailing list manager with user-friendly web front-end

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gnu-COPYING-GPL

CONFLICTS=	ja-mailman-2.1.*

USES=		autoreconf cpe fakeroot python:2.7 shebangfix tar:tgz
USE_RC_SUBR=	mailman
SHEBANG_FILES=	bin/msgfmt.py \
		tests/fblast.py \
		tests/onebounce.py

CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${MAILMANDIR}
CONFIGURE_ARGS+=--with-python=${PYTHON_CMD} \
		--with-username=${MM_USERNAME} \
		--with-groupname=${MM_GROUPNAME} \
		--with-mail-gid=${MAIL_GID} --with-cgi-gid=${CGI_GID} \
		--with-permcheck=no \
		--with-mailhost=localhost \
		--with-urlhost=localhost

# The Mailman port supports a number of variables that may be tweaked at
# build time.  Getting the values of some of them right is crucial!
#
MM_USERNAME?=	mailman
MM_USERID?=	91
MM_GROUPNAME?=	${MM_USERNAME}
MM_GROUPID?=	${MM_USERID}
MM_DIR?=	mailman
CGI_GID?=	www
IMGDIR?=	www/icons
#
# End of user-configurable variables.

USERS=		${MM_USERNAME}
GROUPS=		${MM_GROUPNAME}

MAILMANDIR=	${PREFIX}/${MM_DIR}
PLIST_SUB=	MMDIR=${MM_DIR} IMGDIR=${IMGDIR} MM_USERNAME=${MM_USERNAME} MM_GROUPNAME=${MM_GROUPNAME}
SUB_FILES=	pkg-message pkg-install mailman.newsyslog.sample
SUB_LIST=	MAILMANDIR=${MAILMANDIR} USER=${MM_USERNAME} GROUP=${MM_GROUPNAME} PYTHON_CMD="${PYTHON_CMD}"
PKGDEINSTALL=	${PKGINSTALL}

PORTDOCS=	ACKNOWLEDGMENTS BUGS FAQ INSTALL NEWS README README-I18N.en \
		README.CONTRIB README.NETSCAPE \
		README.USERAGENT TODO UPGRADING \
		mailman-admin.txt \
		mailman-install.txt \
		mailman-member.txt \
		FreeBSD-post-install-notes

OPTIONS_SINGLE=	MTA
OPTIONS_SINGLE_MTA=	COURIER EXIM4 OPENSMTPD POSTFIX SENDMAIL
OPTIONS_DEFINE=	HTDIG NAMAZU2 NLS DOCS
OPTIONS_DEFAULT=	SENDMAIL
COURIER_DESC=	for use with courier
EXIM4_DESC=	for use with exim4
OPENSMTPD_DESC=	for use with opensmtpd - EXPERIMENTAL -
POSTFIX_DESC=	for use with postfix
SENDMAIL_DESC=	for use with sendmail
HTDIG_DESC=	- EXPERIMENTAL - htdig integration patches
NAMAZU2_DESC=	Make private archives searchable with namazu2
MTA_DESC=	Integrate with which MTA?

.include <bsd.port.options.mk>

# enforce EXAMPLES option, necessary so that @sample
# can install the newsyslog file
.if empty(PORT_OPTIONS:MEXAMPLES)
PORT_OPTIONS+=	EXAMPLES
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
MAKE_ARGS+=	LANGUAGES=en
.endif

.if ${PORT_OPTIONS:MSENDMAIL}
MAIL_GID?=	mailnull
.endif

.if ${PORT_OPTIONS:MEXIM4}
MAIL_GID?=	mail
.endif

.if ${PORT_OPTIONS:MPOSTFIX}
BUILD_DEPENDS+=	postfix:mail/postfix
RUN_DEPENDS+=	postfix:mail/postfix
MAIL_GID?=	mailman
EXTRA_PATCHES+=	${FILESDIR}/postfix-verp.diff
.endif

.if ${PORT_OPTIONS:MCOURIER}
MAIL_GID?=	courier
.endif

.if ${PORT_OPTIONS:MOPENSMTPD}
MAIL_GID?=	_smtpd
.endif

.if ${PORT_OPTIONS:MHTDIG}
PKGNAMESUFFIX+=	-with-htdig
# how to create PATCHFILES:
#X identify what is the version of msapiro's patches corresponding to the release.
#X fetch http://bazaar.launchpad.net/~msapiro/mailman/htdig/tarball/1702
#X unpack this tarball, and the original distfile
#X diff -NEur original-unpack bazaar-unpack | xz --best -c >msapiro-htdig-1702.patch.xz
#X upload the latter with mode 0644 or similar to freefall's public_distfiles/ directory
_HTDIGREV=	1734
PATCHFILES+=	msapiro-htdig-${_HTDIGREV}.patch.xz
RUN_DEPENDS+=	htdig:textproc/htdig
PLIST_SUB+=	SUB_HTDIG=""
.else
PLIST_SUB+=	SUB_HTDIG="@comment "
.endif

.if ${PORT_OPTIONS:MNAMAZU2}
RUN_DEPENDS+=	mknmz:databases/namazu2
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Mailman-Cgi-private.py
.endif

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${PY_FLAVOR}

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may change the following build options:"
	@${ECHO} ""
	@${ECHO} "Option		Default Value	Description"
	@${ECHO} "-------------	---------------	------------------------------------------------"
	@${ECHO} "MM_USERNAME	mailman		The username of the Mailman user."
	@${ECHO} "MM_USERID	91		The user ID of the Mailman user."
	@${ECHO} "MM_GROUPNAME	mailman		The group to which the Mailman user will belong."
	@${ECHO} "MM_GROUPID	\$$MM_USERID	The group ID for the Mailman user."
	@${ECHO} "MM_DIR		mailman		Mailman will be installed in"
	@${ECHO} "				${PREFIX}/${MM_DIR}."
	@${ECHO} "CGI_GID		www		The group name or id under which your web"
	@${ECHO} "				server executes CGI scripts."
	@${ECHO} "IMGDIR		www/icons	Icon images will be installed in"
	@${ECHO} "				${PREFIX}/${IMGDIR}."
	@${ECHO} ""

post-patch:
	${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' \
	  ${WRKSRC}/Mailman/Defaults.py.in
	${REINPLACE_CMD} -e 's/^0,5,10/#&/' ${WRKSRC}/cron/crontab.in.in
.if empty(PORT_OPTIONS:MNLS)
	${REINPLACE_CMD} -e 's/messages//' ${WRKSRC}/Makefile.in
.endif
	${MV} ${WRKSRC}/configure.in ${WRKSRC}/configure.ac # suppress warning

.if ${PORT_OPTIONS:MPOSTFIX}
pre-configure:
	${ECHO} "MTA = 'Postfix'" >> ${WRKSRC}/Mailman/mm_cfg.py.dist.in
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/mailman.newsyslog.sample ${STAGEDIR}${EXAMPLESDIR}
.for i in admindb admin confirm create edithtml listinfo options private \
	rmlist roster subscribe
	${STRIP_CMD} ${STAGEDIR}${MAILMANDIR}/cgi-bin/${i}
.endfor
.if ${PORT_OPTIONS:MHTDIG}
.for i in htdig mmsearch
	${STRIP_CMD} ${STAGEDIR}${MAILMANDIR}/cgi-bin/${i}
.endfor
.endif
	${STRIP_CMD} ${STAGEDIR}${MAILMANDIR}/mail/mailman
# Compile additional Python scripts:
.for dir in bin
	(cd ${STAGEDIR}${MAILMANDIR} \
	    && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	    -d ${MAILMANDIR}/${dir} ${dir})
.endfor
	@${RM} ${STAGEDIR}${MAILMANDIR}/pythonlib/*.egg-info
	@# mm_cfg.py is handled by pkg-plist, no need to archive a copy:
	@${RM} ${STAGEDIR}${MAILMANDIR}/Mailman/mm_cfg.py
	@${RM} ${STAGEDIR}${MAILMANDIR}/Mailman/mm_cfg.pyc
	@${MKDIR} ${STAGEDIR}${PREFIX}/${IMGDIR}
	${CP} -p ${STAGEDIR}${MAILMANDIR}/icons/* ${STAGEDIR}${PREFIX}/${IMGDIR}
	${INSTALL_DATA} ${FILESDIR}/powerlogo.png \
	  ${STAGEDIR}${PREFIX}/${IMGDIR}/
	${INSTALL_DATA} ${FILESDIR}/powerlogo.png \
	  ${STAGEDIR}${MAILMANDIR}/icons/
.if ${PORT_OPTIONS:MDOCS}
	${CP} -R ${WRKSRC}/doc/* ${WRKSRC}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/FreeBSD-post-install-notes ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS:NFreeBSD-post-install-notes}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${ECHO} "This marker file ensures that Python's upgrade-site-packages handles ${PKGNAME}." >${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mailman-info.txt
	${INSTALL_SCRIPT} ${PKGINSTALL} ${STAGEDIR}${MAILMANDIR}/bin/FreeBSD-post-install

.include <bsd.port.mk>
