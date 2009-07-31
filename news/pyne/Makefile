# ex:ts=8
# New ports collection makefile for:	pyne
# Date created:			Dec 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pyne
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	news python mail
MASTER_SITES=	http://www.soul-less.pwp.blueyonder.co.uk/pyne/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 offline Newsreader/Emailer

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src/po
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/src/po

USE_GNOME=	pygtk2
USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/# Originally/# coding:latin1/g' \
		${WRKSRC}/src/po/pygettext.py

pre-build:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/pyne.sh
	@${ECHO_CMD} "exec ${PYTHON_CMD} -O ${PYTHON_SITELIBDIR}/pyne/pyne.py \$$*" >> ${WRKDIR}/pyne.sh

post-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} yencdec.c -o yencdec

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pyne.sh ${PREFIX}/bin/pyne
	${INSTALL_PROGRAM} ${WRKSRC}/yencdec  ${PREFIX}/bin/yencdec
	@${MKDIR} ${PYTHON_SITELIBDIR}/pyne
	${TAR} -C ${WRKSRC}/src --exclude po --exclude test -cf - . | \
		${TAR} -C ${PYTHON_SITELIBDIR}/pyne --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PYTHON_SITELIBDIR}/pyne
	${PYTHON_CMD} -O -c "import compileall ; compileall.compile_dir(\"${PYTHON_SITELIBDIR}/pyne\")"

.include <bsd.port.mk>
