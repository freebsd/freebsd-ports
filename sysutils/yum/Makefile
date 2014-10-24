# Created by: Anders F Bjorklund <afb@rpm5.org>
# $FreeBSD$

PORTNAME=	yum
PORTVERSION=	3.4.3
CATEGORIES=	sysutils
MASTER_SITES=	http://yum.baseurl.org/download/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Installer/updater for rpm

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		msgfmt:${PORTSDIR}/devel/gettext \
		intltool-update:${PORTSDIR}/textproc/intltool
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/rpm:${PORTSDIR}/archivers/rpm4 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/sqlitecachec.py:${PORTSDIR}/devel/py-yum-metadata-parser \
		${PYTHON_SITELIBDIR}/iniparse:${PORTSDIR}/devel/py-iniparse \
		${PYTHON_SITELIBDIR}/urlgrabber:${PORTSDIR}/www/py-urlgrabber

USES=		gettext gmake python

MAKE_ARGS=	MAKE=${MAKE_CMD} PYTHON=${PYTHON_CMD} \
		prefix=${PREFIX} mandir=${MANPREFIX}/man sysconfdir=${PREFIX}/etc

RPMDIR?=	/var/lib/rpm

post-patch:
	${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' -e \
	's|@RPMDIR@|${RPMDIR}|g' -e \
	's|@LOCALBASE@|${LOCALBASE}|g' \
		${WRKSRC}/bin/yum.py \
		${WRKSRC}/bin/yum-updatesd.py \
		${WRKSRC}/cli.py \
		${WRKSRC}/yum-updatesd.py \
		${WRKSRC}/yum/__init__.py \
		${WRKSRC}/yum/config.py \
		${WRKSRC}/yum/rpmsack.py \
		${WRKSRC}/yum/plugins.py
	${REINPLACE_CMD} -e 's|#!/usr/bin/python|#!${PYTHON_CMD}|' \
		${WRKSRC}/bin/yum.py \
		${WRKSRC}/bin/yum-updatesd.py \
		${WRKSRC}/callback.py \
		${WRKSRC}/cli.py \
		${WRKSRC}/output.py \
		${WRKSRC}/yumcommands.py \
		${WRKSRC}/yummain.py \
		${WRKSRC}/yum-updatesd.py \
		${WRKSRC}/utils.py \
		${WRKSRC}/rpmUtils/__init__.py \
		${WRKSRC}/rpmUtils/arch.py \
		${WRKSRC}/rpmUtils/miscutils.py \
		${WRKSRC}/rpmUtils/oldUtils.py \
		${WRKSRC}/rpmUtils/transaction.py \
		${WRKSRC}/rpmUtils/updates.py \
		${WRKSRC}/yum/__init__.py \
		${WRKSRC}/yum/Errors.py \
		${WRKSRC}/yum/callbacks.py \
		${WRKSRC}/yum/config.py \
		${WRKSRC}/yum/depsolve.py \
		${WRKSRC}/yum/failover.py \
		${WRKSRC}/yum/history.py \
		${WRKSRC}/yum/i18n.py \
		${WRKSRC}/yum/metalink.py \
		${WRKSRC}/yum/packageSack.py \
		${WRKSRC}/yum/packages.py \
		${WRKSRC}/yum/pkgtag_db.py \
		${WRKSRC}/yum/repoMDObject.py \
		${WRKSRC}/yum/repos.py \
		${WRKSRC}/yum/rpmsack.py \
		${WRKSRC}/yum/rpmtrans.py \
		${WRKSRC}/yum/sqlitesack.py \
		${WRKSRC}/yum/sqlutils.py \
		${WRKSRC}/yum/update_md.py
	${REINPLACE_CMD} -e 's|%%PYTHONPREFIX_SITELIBDIR%%|${PYTHONPREFIX_SITELIBDIR}|' \
		${WRKSRC}/yum/Makefile ${WRKSRC}/rpmUtils/Makefile

.include <bsd.port.mk>
