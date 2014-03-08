# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	pootle
PORTVERSION=	2.1.6
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/translate/Pootle/${PORTVERSION}/
DISTNAME=	Pootle-${PORTVERSION}

MAINTAINER=	catone@cpan.org
COMMENT=	Pootle is a user-friendly web portal for simple translation process

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.2:${PORTSDIR}/www/py-django \
		translate-toolkit>=1.8.1:${PORTSDIR}/textproc/translate-toolkit \
		${PYTHON_PKGNAMEPREFIX}south>=0.7:${PORTSDIR}/databases/py-south

RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN=		Does not install
CONFLICTS=	${PYTHON_PKGNAMEPREFIX}django-profiles-[0-9]* \
		${PYTHON_PKGNAMEPREFIX}django-registration-[0-9]*

USE_BZIP2=	yes
USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	Pootle

POOTLEUSER?=	nobody
POOTLEGROUP?=	nobody

POOTLEDBDIR?=	/var/db/pootle
POOTLELOGDIR?=	/var/log/pootle
POOTLERUNDIR?=	/var/run/pootle

USE_RC_SUBR=	pootle
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

OPTIONS_DEFINE=	MYSQL SUBVERSION MEMCACHED
OPTIONS_DEFAULT=	MYSQL SUBVERSION MEMCACHED
SUBVERSION_DESC=	${SVN_DESC}
MEMCACHED_DESC=	Enable memcached support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MSUBVERSION}
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
LIB_DEPENDS+=	memcached:${PORTSDIR}/databases/libmemcached
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}memcached>=1.45:${PORTSDIR}/databases/py-memcached
.endif

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
		${PREFIX}/etc/pootle/localsettings.py || ${TRUE}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
