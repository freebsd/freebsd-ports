# New ports collection makefile for:	straw
# Date created:		7  Apr 2003
# Whom:			sheldonh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	straw
PORTVERSION=	0.18.1
CATEGORIES=	news
MASTER_SITES=	http://savannah.nongnu.org/download/${PORTNAME}/${PORTNAME}.pkg/${PORTVERSION}/

MAINTAINER=	sheldonh@FreeBSD.org
COMMENT=	A desktop news aggregator for the GNOME 2 desktop

BUILD_DEPENDS=	${LOCALBASE}/include/pyorbit-2/pyorbit.h:${PORTSDIR}/devel/py-orbit2 \
		${LOCALBASE}/bin/pygtk-codegen-2.0:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/mx/DateTime/DateTime.py:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_SITELIBDIR}/bsddb3/db.py:${PORTSDIR}/databases/py-bsddb3 \
		${PYTHON_SITELIBDIR}/_xmlplus/FtCore.py:${PORTSDIR}/textproc/py-xml \
		${PYTHON_SITELIBDIR}/ADNS.py:${PORTSDIR}/net/py-adns \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
WITH_DB3=	yes

MAKE_ARGS+=	PREFIX=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e "s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g" \
	    ${WRKSRC}/src/straw

.include <bsd.port.mk>
