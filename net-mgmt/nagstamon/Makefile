# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagstamon
PORTVERSION=	1.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	https://nagstamon.ifw-dresden.de/files-nagstamon/stable/ \
		CRITICAL
DISTNAME=	Nagstamon-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Nagios status monitor for your desktop

LICENSE=	GPLv2

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox

USES=		python:2
USE_PYTHON=	distutils
USE_GNOME=	pygtk2 librsvg2

WRKSRC=		${WRKDIR}/Nagstamon

post-patch:
	@${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' ${WRKSRC}/setup.py

post-install:
	@${LN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
