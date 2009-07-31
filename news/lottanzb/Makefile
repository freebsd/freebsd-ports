# New ports collection makefile for:	lottanzb
# Date created:		Mon Feb 02 2009
# Whom:			Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
# $Id$
#

PORTNAME=	lottanzb
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.lottanzb.org/releases/

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	A pyGTK usenet frontend for hellanzb

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/kiwi:${PORTSDIR}/x11-toolkits/py-kiwi
RUN_DEPENDS=	hellanzb.py:${PORTSDIR}/news/hellanzb \
		unrar:${PORTSDIR}/archivers/unrar \
		${PYTHON_SITELIBDIR}/kiwi:${PORTSDIR}/x11-toolkits/py-kiwi \
		scrollkeeper-uninstall:${PORTSDIR}/textproc/rarian

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	desktopfileutils
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/try_to_call(\[".*$$//' ${WRKSRC}/setup.py

post-install:
	-@update-desktop-database
	-@update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
