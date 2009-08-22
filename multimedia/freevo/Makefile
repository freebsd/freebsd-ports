# New ports collection makefile for:	freevo
# Date created:		April 10 2004
# Whom:			Lewis Thompson (purple@lewiz.net)
#
# $FreeBSD$
#

PORTNAME=	freevo
PORTVERSION=	1.9.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/Freevo%20releases/${PORTVERSION}

MAINTAINER=	fbsd@opal.com
COMMENT=	Open source digital jukebox

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		aumix:${PORTSDIR}/audio/aumix \
		tv_cat:${PORTSDIR}/textproc/p5-xmltv \
		${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0_1:${PORTSDIR}/devel/py-zopeInterface \
		${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml \
		${PYTHON_SITELIBDIR}/kaa/__init__.py:${PORTSDIR}/multimedia/py-kaa-base \
		${PYTHON_SITELIBDIR}/kaa/imlib2/__init__.py:${PORTSDIR}/multimedia/py-kaa-imlib2 \
		${PYTHON_SITELIBDIR}/kaa/metadata/__init__.py:${PORTSDIR}/multimedia/py-kaa-metadata \
		${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted \
		${PYTHON_SITELIBDIR}/Numeric/Numeric_headers/__init__.py:${PORTSDIR}/math/py-numeric

FREEVO_USER=	freevo
FREEVO_GROUP=	${FREEVO_USER}
FREEVO_UID=	523
FREEVO_GID=	${FREEVO_UID}
FREEVO_HOME=	/var/db/${FREEVO_USER}

SUB_LIST+=	PORTVERSION=${PORTVERSION} \
		FREEVO_USER=${FREEVO_USER} \
		FREEVO_GROUP=${FREEVO_GROUP} \
		FREEVO_UID=${FREEVO_UID} \
		FREEVO_GID=${FREEVO_GID} \
		FREEVO_HOME=${FREEVO_HOME}
SUB_FILES=	pkg-message pkg-install pkg-deinstall

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

USE_RC_SUBR=	${PORTNAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}

CONFDIR=	${PREFIX}/etc/${PORTNAME}
DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e  '451d' ${WRKSRC}/${PORTNAME}
.endif

	@${REINPLACE_CMD} -e 's|/etc/freevo|${PREFIX}/etc/freevo|' ${WRKSRC}/freevo_config.py
	@${REINPLACE_CMD} -e 's|/etc/freevo|${PREFIX}/etc/freevo|' ${WRKSRC}/local_conf.py.example

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${MKDIR} ${CONFDIR}
	${CHMOD} a+rx ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/local_conf.py.example ${CONFDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
