# New ports collection makefile for:	katchtv
# Date created:		2006-05-02
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	katchtv
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	multimedia kde python
MASTER_SITES=	http://www.digitalunleashed.com/downloads/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}_latest_release
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	An Internet TV application (for KDE)

RUN_DEPENDS=	kdepyuic:${PORTSDIR}/x11-toolkits/py-kde \
		kaffeine:${PORTSDIR}/multimedia/kaffeine

BROKEN=		does not work with new kaffeine

NO_BUILD=	yes
USE_BZIP2=	yes

WRKSRC=	${WRKDIR}/KatchTV

FIND_DELETE=	-type f  \( -name "README*" -or -name "LICENSE*" -or -name MANIFEST -or -name TODO -or -name ChangeLog -or -name PKG-INFO \)
FIND_DIRS=	-type d
FIND_DATA=	-type f

LN_OPTS=	-sf

KATCHTV_SCRIPT=	KatchTV

post-extract:
	cd ${WRKSRC} && ${FIND} . ${FIND_DELETE} -delete

do-install:
	cd ${WRKSRC} && ${FIND} . ${FIND_DIRS} -exec ${MKDIR} ${DATADIR}/{} ";"
	cd ${WRKSRC} && ${FIND} . ${FIND_DATA} -exec ${INSTALL_DATA} {} ${DATADIR}/{} ";"
	${INSTALL_SCRIPT} ${WRKSRC}/${KATCHTV_SCRIPT} ${DATADIR}/${KATCHTV_SCRIPT}
	${LN} ${LN_OPTS} ${DATADIR}/${KATCHTV_SCRIPT} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
