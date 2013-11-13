# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagstamon
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION} \
		CRITICAL/.
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Nagios status monitor for your desktop

LICENSE=	GPLv2

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
USE_GNOME=	pygtk2 librsvg2

WRKSRC=		${WRKDIR}/Nagstamon

post-patch:
	@${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' ${WRKSRC}/setup.py

post-install:
	@${LN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
