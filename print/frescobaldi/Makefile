# New ports collection makefile for:   frescobaldi
# Date created:        17 April 2011
# Whom:                martin.dieringer@gmx.de
#
# $FreeBSD$
#

PORTNAME=	frescobaldi
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://lilykde.googlecode.com/files/

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	A music score editor for lilypond

RUN_DEPENDS=	lilypond:${PORTSDIR}/print/lilypond

USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_KDE4=	baseapps kdeprefix kdelibs pykde4_build pykde4_run
USE_CMAKE=	yes
USE_GMAKE=	yes
USE_PYTHON=	2.6+

do-install:
	@cd ${WRKSRC} && ${GMAKE} install

.include <bsd.port.mk>
