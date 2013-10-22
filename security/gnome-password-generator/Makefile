# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	gnome-password-generator
PORTVERSION=	1.6
PORTREVISION=	5
CATEGORIES=	security gnome python
MASTER_SITES=	SF/gnome-password/Gnome%20Password%20Generator/${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	GNOME 2 password generator

USE_GNOME=	pygnome2
USE_PYTHON=	yes

NO_STAGE=	yes
do-build:
	@cd ${WRKSRC} && ${SED} -e 's|/usr/bin/python|${PYTHON_CMD}|g ; \
		 s|/usr/share|${PREFIX}/share|g' ${PORTNAME}.py > ${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.png ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/*.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
