# Created by: Stanislav Svirid <count@211.ru>
# $FreeBSD$

PORTNAME=	noc
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	http://redmine.nocproject.org/attachments/download/137/

MAINTAINER=	count@211.ru
COMMENT=	Operation Support System (OSS) for the Telco, SP, and Enterprise NOC

LICENSE=	BSD

LIB_DEPENDS=	smi:${PORTSDIR}/net-mgmt/libsmi
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.3<1.4:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-tagging>0:${PORTSDIR}/www/py-django-tagging \
		${PYTHON_PKGNAMEPREFIX}south>0:${PORTSDIR}/databases/py-south \
		${PYTHON_PKGNAMEPREFIX}coverage>0:${PORTSDIR}/devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}snmp4>=0:${PORTSDIR}/net-mgmt/py-snmp4 \
		${PYTHON_PKGNAMEPREFIX}creole>0:${PORTSDIR}/textproc/py-creole \
		${PYTHON_PKGNAMEPREFIX}webob>0:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}WebTest>0:${PORTSDIR}/www/py-WebTest \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto

BROKEN=		unsatisfyable dependency object

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-sa_sae.py
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-0.6.4.rst

OPTIONS_DEFINE=	GMPY PEP8
OPTIONS_DEFAULT=GMPY
GMP_DESC=	Use GMP library in SSH
PEP8_DESC=	Intsall pep8 for checking source

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFODIR=	${NOCDIR}

NOCUSER=	noc
NOCGROUP=	noc
NOCDIR?=	${PREFIX}/noc
NOCDBDIR?=	/var/db/noc
LOCALSTATE_DIR?=/var/run/noc

USERS=		${NOCUSER}
GROUPS=		${NOCGROUP}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGMPY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gmpy>0:${PORTSDIR}/math/py-gmpy
.endif

.if ${PORT_OPTIONS:MPEP8}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pep8>0:${PORTSDIR}/devel/pep8
.endif

PLIST_SUB=	NOCDIR=${NOCDIR} \
		NOCDBDIR=${NOCDBDIR} \
		NOCUSER=${NOCUSER} \
		NOCGROUP=${NOCGROUP} \
		NOCUID=${NOCUID} \
		NOCGID=${NOCGID} \
		LOCALSTATE_DIR=${LOCALSTATE_DIR} \
		PYTHONBASE=${PYTHONBASE}

PLIST_REINPLACE+=	noc_static noc_etc noc
PLIST_REINPLACE_NOC=	s@dirrm noc$$@dirrmtry noc@
PLIST_REINPLACE_NOC_STATIC=	s@dirrm noc/static@dirrmtry noc/static@
PLIST_REINPLACE_NOC_ETC=	s@dirrm noc/etc@dirrmtry noc/etc@

PLIST=		${WRKDIR}/.PLIST.noc

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

USE_RC_SUBR=	noc

NOC_CONF_FILES=	etc/noc-activator.defaults \
		etc/noc-classifier.defaults \
		etc/noc-correlator.defaults \
		etc/noc-fcgi.defaults \
		etc/noc-launcher.defaults \
		etc/noc-notifier.defaults \
		etc/noc-probe.defaults \
		etc/noc-sae.defaults \
		etc/noc-scheduler.defaults \
		etc/noc.defaults

post-extract:
	@(cd ${WRKSRC}; \
	    ${RM} -rf contrib/src; \
	    ${REINPLACE_CMD} -e "/^contrib\/src/ d;" MANIFEST ; \
	    ${REINPLACE_CMD} -e "/^contrib/ d;" MANIFEST-ACTIVATOR ; \
	)

post-patch:
	@(cd ${WRKSRC}; \
	${REINPLACE_CMD} -e "s@^\(pidfile *=\).*/\([^/]*.pid\)@\1 ${LOCALSTATE_DIR}/\2@" ${NOC_CONF_FILES}; \
	${REINPLACE_CMD} -e "s@^\(repo *=\).*@\1 ${NOCDBDIR}/repo@" -e "s@^\(backup_dir *=\).*@\1 ${NOCDBDIR}/backup@" etc/noc.defaults; \
	${REINPLACE_CMD} -e "s@^\(PREFIX=\"\).*@\1${NOCDIR}\"@" setup.py; \
	_sed_script=`${MKTEMP} tmp.XXXXXX`; \
	for cmd in ssh rsync pg_dump tar gzip smidump smilint fping dig gpg; do \
		${ECHO_CMD} "s@^\\($${cmd} *\\)=.*\$$@\\1 = "`${WHICH} $${cmd}`'@' >> $${_sed_script} ; \
	done; \
	${REINPLACE_CMD} -f $${_sed_script} ${NOC_CONF_FILES}; \
	${RM} $${_sed_script}; )

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL
	@>${PLIST}
.for f in ${NOC_CONF_FILES}
	@${ECHO_CMD} "@unexec if cmp -s %D/noc/${f} %D/noc/${f:R}.conf; then rm -f %D/noc/${f:R}.conf; fi" >> ${PLIST}
.endfor
	@(${CAT} ${WRKSRC}/MANIFEST | ${SED} -e '/^.hg/d; s@^@noc\/@;' \
		-e '/.py$$/ {p; s/.py$$/.pyc/p; s/.pyc$$/.pyo/;} ' | \
		${EGREP} -v 'noc/(scripts/|setup|share/docs/).*\.py[co]' | \
		${SORT} >> ${PLIST} )
	@${ECHO_CMD} "@dirrmtry ${NOCDIR:S%^${PREFIX}/%%}/local" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry ${NOCDIR:S%^${PREFIX}/%%}/static/doc" >> ${PLIST}
	@(_sed_script=`${MKTEMP} ${WRKDIR}/tmp.XXXXXX`; \
	    ${ECHO_CMD} "/^.hg/d" >> $${_sed_script} ;\
	    ${ECHO_CMD} "s@^@noc\/@" >> $${_sed_script} ;\
	    ${ECHO_CMD} ":u" >> $${_sed_script} ;\
	    ${ECHO_CMD} '/\// { s/^[^@]/@dirrm &/; s@/[^/]*$$@@; p; }' >> $${_sed_script} ;\
	    ${ECHO_CMD} "tu" >> $${_sed_script} ;\
	    ${ECHO_CMD} "d" >> $${_sed_script} ;\
	    ${CAT} ${WRKSRC}/MANIFEST | ${SED} -f $${_sed_script} | ${SORT} -r -u  >> ${PLIST} ;\
	    ${RM} $${_sed_script}; \
	)
	@${ECHO_CMD} "@cwd ${NOCDBDIR}" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry repo" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry backup" >> ${PLIST}
	@${ECHO_CMD} "@unexec rmdir ${NOCDBDIR} 2>/dev/null || true" >> ${PLIST}
	@${ECHO_CMD} "@cwd /" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry ${LOCALSTATE_DIR}" >> ${PLIST}

post-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
