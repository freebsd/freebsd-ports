# New ports collection makefile for:	pootle
# Date created:		14 Dec 2009
# Whom:			Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	pootle
PORTVERSION=	2.0.4
CATEGORIES=	textproc
MASTER_SITES=	SF/translate/Pootle/${PORTVERSION}/
DISTNAME=	Pootle-${PORTVERSION}

MAINTAINER=	catone@cpan.org
COMMENT=	Pootle is a user-friendly web portal for simple translation process

BUILD_DEPENDS=	py*-django>=1.1:${PORTSDIR}/www/py-django \
		translate-toolkit>=1.6:${PORTSDIR}/textproc/translate-toolkit

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	Pootle

POOTLEUSER?=	nobody
POOTLEGROUP?=	nobody

POOTLEDBDIR?=	/var/db/pootle
POOTLELOGDIR?=	/var/log/pootle
POOTLERUNDIR?=	/var/run/pootle

USE_RC_SUBR=	pootle.sh
SUB_LIST+=	PYTHON_CMD="${PYTHON_CMD}" \
		POOTLEDBDIR="${POOTLEDBDIR}" \
		POOTLELOGDIR="${POOTLELOGDIR}" \
		POOTLERUNDIR="${POOTLERUNDIR}" \
		POOTLEUSER="${POOTLEUSER}" \
		POOTLEGROUP="${POOTLEGROUP}" \
		CHOWN="${CHOWN}" \
		CHMOD="${CHMOD}" \
		MKDIR="${MKDIR}"

PLIST_SUB+=	POOTLEDBDIR="${POOTLEDBDIR}" \
		POOTLELOGDIR="${POOTLELOGDIR}"

SUB_FILES+=	pkg-install
PKGINSTALL=	${WRKDIR}/pkg-install

PORTDOCS=	ChangeLog COPYING INSTALL README wsgi.py

.include <bsd.port.pre.mk>

post-patch:
	@${MV} ${WRKSRC}/localsettings.py ${WRKSRC}/localsettings.py.sample
	@${REINPLACE_CMD} -e "s|^CONFIG_DIR.*=.*|CONFIG_DIR = \'${PREFIX}/etc/pootle\'|g" \
		-e "s|^DATA_DIR.*=.*|DATA_DIR = \\'${DATADIR}\\'|g" \
		-e "s|^WORKING_DIR.*=.*|WORKING_DIR = \\'${POOTLEDBDIR}\\'|g" \
		${WRKSRC}/pootle/install_dirs.py
	@${REINPLACE_CMD} -e "s|^INSTALL_CONFIG_DIR.*=.*|INSTALL_CONFIG_DIR = \'${PREFIX}/etc/pootle\'|g" \
		-e "s|^INSTALL_WORKING_DIR.*=.*|INSTALL_WORKING_DIR = \'${POOTLEDBDIR}\'|g" \
		${WRKSRC}/setup.py

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CP} -n ${PREFIX}/etc/pootle/localsettings.py.sample \
		${PREFIX}/etc/pootle/localsettings.py

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
