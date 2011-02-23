# New ports collection makefile for:	lottanzb
# Date created:		Mon Feb 02 2009
# Whom:			Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
# $Id$
#

PORTNAME=	lottanzb
PORTVERSION=	0.6
CATEGORIES=	news
MASTER_SITES=	http://www.lottanzb.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pyGTK usenet frontend for hellanzb

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/kiwi:${PORTSDIR}/x11-toolkits/py-kiwi
RUN_DEPENDS=	hellanzb.py:${PORTSDIR}/news/hellanzb \
		unrar:${PORTSDIR}/archivers/unrar \
		${PYTHON_SITELIBDIR}/kiwi:${PORTSDIR}/x11-toolkits/py-kiwi \
		scrollkeeper-uninstall:${PORTSDIR}/textproc/rarian

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	desktopfileutils intltool
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

PORTDOCS=	README NEWS

MAN1=	lottanzb.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/try_to_call(\[".*$$//' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's/.share., \(.man.\)/\1/; s/^ *__stdfiles(attrs, src)//' \
	${WRKSRC}/distutilsextra/auto.py
post-install:
	-@update-desktop-database
	-@update-mime-database ${PREFIX}/share/mime
	-@gtk-update-icon-cache -q -f ${PREFIX}/share/icons/hicolor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
