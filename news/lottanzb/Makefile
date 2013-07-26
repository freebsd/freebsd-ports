# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	lottanzb
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	http://www.lottanzb.org/releases/ \
		http://launchpadlibrarian.net/64247317/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	pyGTK usenet frontend for hellanzb

LICENSE=	GPLv3

RUN_DEPENDS=	SABnzbd.py:${PORTSDIR}/news/sabnzbdplus \
		yelp:${PORTSDIR}/x11/yelp \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip \
		${PYTHON_PKGNAMPREFIX}yenc>=0:${PORTSDIR}/news/py-yenc \
		${PYTHON_PKGNAMPREFIX}feedparser>=0:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27
BROKEN=		overwrite a file owned by misc/shared-mime-info: share/mime/application/x-nzb.xml

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	desktopfileutils intltool
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USES=		shared-mime-info desktop-file-utils

PORTDOCS=	README NEWS

MAN1=		lottanzb.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/try_to_call(\[".*$$//' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's/.share., \(.man.\)/\1/; s/^ *__stdfiles(attrs, src)//' \
	${WRKSRC}/distutilsextra/auto.py
post-install:
	-@gtk-update-icon-cache -q -f ${PREFIX}/share/icons/hicolor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
