# New ports collection makefile for:	noc
# Date created:				27.08.2009
# Whom:					Stanislav Svirid <count@211.ru>
#
# $FreeBSD$
#

PORTNAME=	noc
PORTVERSION=	0.3.2
CATEGORIES=	net-mgmt python
MASTER_SITES=	http://trac.nocproject.org/trac/downloads/
DISTNAME=	noc-${PORTVERSION}

MAINTAINER=	count@211.ru
COMMENT=	Operation Support System (OSS) for the Telco, SP and Enterprise NOC

LIB_DEPENDS=	smi.2:${PORTSDIR}/net-mgmt/libsmi
BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools \
    		${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup
RUN_DEPENDS=	django-admin.py:${PORTSDIR}/www/py-django \
		${PYTHON_SITELIBDIR}/psycopg2/_psycopg.so:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_SITELIBDIR}/pysnmp/v4/__init__.py:${PORTSDIR}/net-mgmt/py-snmp4 \
		${PYTHON_PKGNAMEPREFIX}south>0:${PORTSDIR}/databases/py-south \
		${PYTHON_PKGNAMEPREFIX}creole>0:${PORTSDIR}/textproc/py-creole \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:${PORTSDIR}/devel/py-protobuf

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFODIR=	${NOCDIR}

CONFLICTS=	noc-devel-[0-9].*

NOCUSER?=	noc
NOCGROUP?=	noc
NOCDIR?=	${PREFIX}/noc
NOCDBDIR?=	/var/db/noc
LOCALSTATE_DIR?=/var/run/noc

NOCUID=		182
NOCGID=		${NOCUID}

.include <bsd.port.pre.mk>

PLIST_SUB=	NOCDIR=${NOCDIR} \
		NOCDBDIR=${NOCDBDIR} \
		NOCUSER=${NOCUSER} \
		NOCGROUP=${NOCGROUP} \
		NOCUID=${NOCUID} \
		NOCGID=${NOCGID} \
		LOCALSTATE_DIR=${LOCALSTATE_DIR} \
		PYTHONBASE=${PYTHONBASE}

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

USE_RC_SUBR=	noc.sh

NOC_CONF_FILES=	etc/noc-activator.defaults \
		etc/noc-classifier.defaults \
		etc/noc-correlator.defaults \
		etc/noc-fcgi.defaults \
		etc/noc-launcher.defaults \
		etc/noc-notifier.defaults \
		etc/noc-sae.defaults \
		etc/noc-probe.defaults \
		etc/noc.defaults

post-patch:
	@(cd ${WRKSRC}; \
	${REINPLACE_CMD} -e "s@^\(pidfile *=\).*/\([^/]*.pid\)@\1 ${LOCALSTATE_DIR}/\2@" ${NOC_CONF_FILES}; \
	${REINPLACE_CMD} -e "s@^\(repo *=\).*@\1 ${NOCDBDIR}/repo@" -e "s@^\(backup_dir *=\).*@\1 ${NOCDBDIR}/backup@" etc/noc.defaults; \
	${REINPLACE_CMD} -e "s@^\(PREFIX=\"\).*@\1${NOCDIR}\"@" setup.py; \
	_sed_script=`${MKTEMP} tmp.XXXXXX`; \
	for cmd in telnet ssh rsync pg_dump tar gzip smidump smilint fping dig gpg; do \
		${ECHO} "s@^\\($${cmd} *\\)=.*\$$@\\1 = "`${WHICH} $${cmd}`'@' >> $${_sed_script} ; \
	done; \
	${REINPLACE_CMD} -f $${_sed_script} ${NOC_CONF_FILES}; \
	${RM} $${_sed_script}; )

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
