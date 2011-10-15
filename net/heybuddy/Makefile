# New ports collection makefile for:   heybuddy
# Date created:        14 April 2011
# Whom:                Beni Keller <navigium@grindcore.ch>
#
# $FreeBSD$
#

PORTNAME=	heybuddy
PORTVERSION=	0.2.2
CATEGORIES=	net
MASTER_SITES=	http://launchpad.net/${PORTNAME}/0.2/${PORTVERSION}/+download/ \
		http://freebsd.grindcore.ch/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	navigium@grindcore.ch
COMMENT=	A supposedly light, feature free identi.ca client

LICENSE=	GPLv3

FETCH_ARGS=	-Fpr
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GNOME=	pygtk2

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/heybuddy.py
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/heybuddy.py

do-build:
	${PYTHON_CMD} -mcompileall ${WRKSRC}

do-install:
	@${RM} ${WRKSRC}/ChangeLog ${WRKSRC}/gpl-3.0.txt
	@${MV} ${WRKSRC}/*.bak ${WRKDIR}
	@${MV} ${WRKSRC}/*.orig ${WRKDIR}
	@${MV} ${WRKSRC}/locales ${WRKDIR}
	@${MV} ${WRKSRC}/${PORTNAME}.py ${WRKDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR})
	(cd ${WRKDIR}/locales && ${COPYTREE_SHARE} . ${PREFIX}/share/locale)
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
