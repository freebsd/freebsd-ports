# ex:ts=8
# Ports collection makefile for:	py-libnet
# Date created:			Jan 30, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pylibnet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibnet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for the libnet packet construction library

BUILD_DEPENDS=	${LOCALBASE}/bin/swig1.1:${PORTSDIR}/devel/swig11 \
		${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; \
		s,%%PYTHON_INCLUDEDIR%%,${PYTHON_INCLUDEDIR},g ; \
		s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile

do-install:
.for file in libnet.py libnetcmodule.so
	${INSTALL_DATA} ${WRKSRC}/${file} ${PYTHON_SITELIBDIR}
.endfor

.include <bsd.port.mk>
