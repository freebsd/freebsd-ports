# New ports collection makefile for:	straw
# Date created:				06 March 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	straw
PORTVERSION=	0.21.1
PORTREVISION=	3
CATEGORIES=	net gnome
#MASTER_SITES=	${MASTER_SITE_SAVANNAH}
#MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}.pkg/${PORTVERSION}/
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     adamw

MAINTAINER=	mezz7@cox.net
COMMENT=	A GNOME 2 desktop weblog aggregator written in Python

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/mx/DateTime/mxDateTime/__init__.py:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	libglade2

.include <bsd.port.pre.mk>

# pybsddb ships with python 2.3
.if ${PYTHON_REL} < 230
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb3
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11PREFIX%%|${PREFIX}|g ; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		${WRKSRC}/Makefile ${WRKSRC}/src/straw

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
