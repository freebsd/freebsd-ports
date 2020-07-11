# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scanmem
PORTVERSION=	0.17
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Locate and modify various data in an executing process

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	requires linprocfs(5)

USES=		autoreconf gettext-tools gmake gnome libtool readline
USE_GITHUB=	yes
USE_GNOME=	intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_file__proc_self_maps=yes \
		ac_cv_file__proc_self_mem=yes

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_SUB=	yes

X11_DESC=	Install PyGTK-based GUI (GameConqueror)
X11_CATEGORIES=	python
X11_CONFIGURE_ON=	--enable-gui
X11_USES=	python:run shebangfix
X11_USE=	GNOME=gtk30,pygobject3
X11_VARS=	SHEBANG_FILES+=gui/GameConqueror.py

post-patch:
	@${REINPLACE_CMD} -e 's,/proc/,/compat/linux&,' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's, COPYING,,' ${WRKSRC}/gui/Makefile.am

.include <bsd.port.mk>
