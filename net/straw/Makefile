# New ports collection makefile for:	straw
# Date created:				06 March 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	straw
PORTVERSION=	0.25.1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME 2 desktop weblog aggregator written in Python

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	libglade2 pygnome2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} \
				--install-lib=${PREFIX}/share/gnome \
				--with-desktop-file-dir=share/gnome/applications

.include <bsd.port.pre.mk>

# pybsddb ships with python 2.3
.if ${PYTHON_REL} < 230
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb3
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb3
.else
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		${WRKSRC}/src/straw

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
