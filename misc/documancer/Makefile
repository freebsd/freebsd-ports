# ex:ts=8
# Ports collection makefile for:	documancer
# Date created:			Oct 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	documancer
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A programmer's documentation reader

BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		swish-e:${PORTSDIR}/www/swish-e
LIB_DEPENDS=	wxmozilla_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxmozilla
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython

USE_PYTHON=	2.3
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

PLIST_FILES=	bin/documancer

post-install:
	@${FIND} ${DATADIR} -type f | ${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
