# New ports collection makefile for:	lottanzb
# Date created:		Mon Feb 02 2009
# Whom:			Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
# $Id$
#

PORTNAME=	lottanzb
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	http://www.lottanzb.org/releases/ \
		http://launchpadlibrarian.net/64247317/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pyGTK usenet frontend for hellanzb

LICENSE=	GPLv3

RUN_DEPENDS=	SABnzbd.py:${PORTSDIR}/news/sabnzbdplus \
		yelp:${PORTSDIR}/x11/yelp \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		${PYTHON_SITELIBDIR}/yenc.py:${PORTSDIR}/news/py-yenc \
		${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl

BROKEN=		overwrite a file owned by misc/shared-mime-info: share/mime/application/x-nzb.xml

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	desktopfileutils intltool
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

PORTDOCS=	README NEWS

MAN1=		lottanzb.1

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

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
