# Created by: Lewis Thompson (purple@lewiz.net)
# $FreeBSD$

PORTNAME=	freevo
PORTVERSION=	1.9.0
PORTREVISION=	19
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/Freevo%20releases/${PORTVERSION}

MAINTAINER=	fbsd@opal.com
COMMENT=	Open source digital jukebox

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	mplayer:multimedia/mplayer \
		mencoder:multimedia/mencoder \
		aumix:audio/aumix \
		tv_cat:textproc/p5-xmltv \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.3.0_1:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/kaa/__init__.py:multimedia/py-kaa-base@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/kaa/imlib2/__init__.py:multimedia/py-kaa-imlib2@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/kaa/metadata/__init__.py:multimedia/py-kaa-metadata@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/BeautifulSoup.py:www/py-beautifulsoup32@${PY_FLAVOR} \
		${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/Numeric/Numeric_headers/__init__.py:math/py-numeric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

FREEVO_USER=	freevo
FREEVO_GROUP=	${FREEVO_USER}
FREEVO_HOME=	/var/db/${FREEVO_USER}

USERS=		${FREEVO_USER}
GROUPS=		${FREEVO_GROUP}

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD} \
		PORTVERSION=${PORTVERSION} \
		FREEVO_HOME=${FREEVO_HOME}
SUB_FILES=	pkg-message pkg-deinstall

NO_ARCH=	yes
USES=		python:2.7 shebangfix
USE_PYTHON=	distutils noegginfo
PYDISTUTILS_INSTALLNOSINGLE=	yes
PYDISTUTILS_SETUP=	${PYSETUP}
SHEBANG_FILES=	src/www/htdocs/downloadurl

PLIST_SUB=	PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO}

USE_RC_SUBR=	${PORTNAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}

CONFDIR=	${PREFIX}/etc/${PORTNAME}
DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's| freevo_locale| # freevo_locale|' ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/i18n ${WRKSRC}/i18n-nls-disabled
.endif
	@${REINPLACE_CMD} -e 's|/etc/freevo|${PREFIX}/etc/freevo|' ${WRKSRC}/freevo_config.py
	@${REINPLACE_CMD} -e 's|/etc/freevo|${PREFIX}/etc/freevo|' ${WRKSRC}/local_conf.py.example
	@${MV} ${WRKSRC}/src/www/htdocs/favorites.rpy.orig ${WRKDIR}
	@${MV} ${WRKSRC}/src/www/htdocs/search.rpy.orig ${WRKDIR}
	@${RM} ${WRKSRC}/src/www/htdocs/fileinfo.rpy.orig ${WRKSRC}/src/www/htdocs/guide.rpy.orig \
		${WRKSRC}/src/www/htdocs/guidechannel.rpy.orig ${WRKSRC}/src/www/htdocs/proginfo.rpy.orig \
		${WRKSRC}/src/www/htdocs/vlcwin.rpy.orig

do-configure:
	@${DO_NADA}

post-install:
	${MKDIR} ${STAGEDIR}${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/local_conf.py.example ${STAGEDIR}${CONFDIR}
	${MKDIR} ${STAGEDIR}/var/log/freevo
	${MKDIR} ${STAGEDIR}/var/run/freevo

.include <bsd.port.mk>
