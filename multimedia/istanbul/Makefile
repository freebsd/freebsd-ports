# New ports collection makefile for: istanbul
# Date created:        2005-07-03
# Whom:                Dominique Goncalves <dominique.goncalves@gmail.com>
#
# $FreeBSD$

PORTNAME=		istanbul
PORTVERSION=		0.1.1
CATEGORIES=		multimedia
MASTER_SITES=		http://live.hujjat.org/

MAINTAINER=		dominique.goncalves@gmail.com
COMMENT=		Istanbul is a desktop session recorder for the Free Desktop

RUN_DEPENDS=		icecast:${PORTSDIR}/audio/icecast2 \
			${PYTHON_SITELIBDIR}/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer
BUILD_DEPENDS=		${PYTHON_SITELIBDIR}/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer

USE_GNOME=		pygtk2
USE_GMAKE=		yes
USE_LIBTOOL_VER=	15
USE_PYTHON=		2.4+
USE_BZIP2=		yes
USE_X_PREFIX=		yes
USE_GSTREAMER=		shout2 theora ogg
USE_REINPLACE=		yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
BROKEN="Configure Fails"
.endif

post-configure:
			${REINPLACE_CMD} -e "s|#!/usr/bin/python|#!/usr/bin/env python|" `${FIND} ${WRKDIR} -type f -name "istanbul"`

.include <bsd.port.post.mk>
