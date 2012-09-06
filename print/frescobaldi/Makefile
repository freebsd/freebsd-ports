# New ports collection makefile for:   frescobaldi
# Date created:        17 April 2011
# Whom:                martin.dieringer@gmx.de
#
# $FreeBSD$
#

PORTNAME=	frescobaldi
PORTVERSION=	2.0.7
CATEGORIES=	print kde
MASTER_SITES=	http://cloud.github.com/downloads/wbsoft/frescobaldi/

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	A music score editor for lilypond

RUN_DEPENDS=	lilypond:${PORTSDIR}/print/lilypond \
		${PYTHON_SITELIBDIR}/popplerqt4.so:${PORTSDIR}/graphics/py-poppler-qt4

USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_KDE4=	kdeprefix kdelibs pykde4_build pykde4_run
USE_PYTHON=	2.6+
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
