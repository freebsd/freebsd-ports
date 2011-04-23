# New ports collection makefile for:   heybuddy
# Date created:        14 April 2011
# Whom:                Beni Keller <navigium@grindcore.ch>
#
# $FreeBSD$
#

PORTNAME=	heybuddy
PORTVERSION=	0.2.1
CATEGORIES=	net
MASTER_SITES=	http://launchpad.net/${PORTNAME}/0.2/${PORTVERSION}/+download/ \
		http://freebsd.grindcore.ch/distfiles/

MAINTAINER=	navigium@grindcore.ch
COMMENT=	Heybuddy is a supposedly light, feature free identi.ca client

FETCH_ARGS=	-Fpr

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GNOME=	pygtk2

do-build:
	${PYTHON_CMD} -mcompileall ${WRKSRC}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}
	${LN} -s ${DATADIR}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}

post-install:
	${RM} ${DATADIR}/*.txt ${DATADIR}/ChangeLog

.include <bsd.port.mk>
