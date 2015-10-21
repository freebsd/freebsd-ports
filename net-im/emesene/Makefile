# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	emesene
PORTVERSION=	2.12.9
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instant messenging client written in python

LICENSE=	GPLv3 # (or later)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}notify>0:${PORTSDIR}/devel/py-notify \
		${PYTHON_PKGNAMEPREFIX}openssl>0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>0:${PORTSDIR}/www/py-webkitgtk \
		xprop:${PORTSDIR}/x11/xprop

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes

USES=		desktop-file-utils gettext-runtime python
USE_GNOME=	pygtk2:run
USE_GSTREAMER=	python
INSTALLS_ICONS=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/emesene
	(cd ${WRKSRC}/emesene && ${INSTALL_SCRIPT} emesene \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/emesene)
	(cd ${WRKSRC}/emesene && ${INSTALL_DATA} *.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/emesene)
	(cd ${WRKSRC}/emesene && ${COPYTREE_SHARE} \
		"e3 gui interfaces plugins po test themes" \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/emesene)
	${LN} -sf ${PYTHONPREFIX_SITELIBDIR}/emesene/emesene \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/docs/man && ${INSTALL_MAN} emesene.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC}/emesene/data && ${COPYTREE_SHARE} "icons pixmaps" \
		${STAGEDIR}${PREFIX}/share)
	(cd ${WRKSRC}/emesene/data/share/applications && ${INSTALL_DATA} \
		emesene.desktop ${STAGEDIR}${PREFIX}/share/applications)
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
