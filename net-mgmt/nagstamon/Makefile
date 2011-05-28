# New ports collection makefile for:	nagstamon
# Date created:				26 May 2011
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagstamon
PORTVERSION=	0.9.7
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF/nagstamon/nagstamon/SVN/ CRITICAL/.
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Nagios status monitor for your desktop

BUILD_DEPENDS=	py*-setuptools>=0:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		py*-setuptools>=0:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
USE_GNOME=	pygtk2 librsvg2

LICENSE=	GPLv2

MAN1=		nagstamon.1

MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/Nagstamon

post-patch:
	@${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' ${WRKSRC}/setup.py

post-install:
	@${LN} ${PREFIX}/bin/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
