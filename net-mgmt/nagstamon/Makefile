# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagstamon
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	net-mgmt python
MASTER_SITES=	https://nagstamon.ifw-dresden.de/files/very_stable/ \
		LOCAL/ehaupt
DISTNAME=	Nagstamon-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Nagios status monitor for your desktop

LICENSE=	GPLv2

RUN_DEPENDS=	sox:audio/sox \
		${PYTHON_PKGNAMEPREFIX}keyring>=1.3:security/py-keyring@${FLAVOR}

USES=		cpe python:2.7
CPE_VENDOR=	henri_wahl
USE_PYTHON=	distutils
USE_GNOME=	pygtk2 librsvg2
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/Nagstamon

post-patch:
	@${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' ${WRKSRC}/setup.py

post-install:
	@${LN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
