# New ports collection makefile for:	gcipher
# Date created:		25 June 2003
# Whom:			Shannon -jj Behrens <jjinux@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	gcipher
PORTVERSION=	1.0
PORTREVISION=	12
CATEGORIES=	security gnome
MASTER_SITES=	SF

MAINTAINER=	jjinux@yahoo.com
COMMENT=	A simple encryption tool

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_PYTHON=	yes
USE_GNOME=	libgnomeui

GCIPHER_PREFIX=	${PREFIX}/share/gcipher

MAN1=	gcipher.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/Const.py ${WRKSRC}/src/gcipher

do-build:
	(cd ${WRKSRC}/src; \
	 ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py .)

do-install:
	${MKDIR} \
	    ${GCIPHER_PREFIX}/lib/cipher \
	    ${GCIPHER_PREFIX}/lib/ciphergui \
	    ${GCIPHER_PREFIX}/plugins/cipher \
	    ${GCIPHER_PREFIX}/plugins/ciphergui

	(cd ${WRKSRC}; \
	 ${INSTALL_MAN} gcipher.1 ${PREFIX}/man/man1; \
	 ${INSTALL_DATA} CONTRIB LICENSE README "${GCIPHER_PREFIX}")

	(cd ${WRKSRC}/src; \
	 ${INSTALL_SCRIPT} gcipher ${PREFIX}/bin/gcipher; \
	 ${INSTALL_DATA} gcipher.desktop ${PREFIX}/share/applications; \
	 for i in `${FIND} . -name '*.py' \
		       -o -name '*.pyc' \
		       -o -name '*.glade' \
		       -o -name '*.gladep'`; do \
		${INSTALL_DATA} "$$i" "${GCIPHER_PREFIX}/lib/$$i"; \
	 done)

	(cd ${WRKSRC}/plugins; \
	 for i in `${FIND} . -name '*.py' \
		       -o -name '*.glade' \
		       -o -name '*.gladep'`; do \
		${INSTALL_DATA} "$$i" "${GCIPHER_PREFIX}/plugins/$$i"; \
	 done)

.include <bsd.port.mk>
