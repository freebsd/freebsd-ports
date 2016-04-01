# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scanmem
PORTVERSION=	0.13
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	_.tar.gz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Locate and modify various data in an executing process

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	requires linprocfs(5)

USES=		readline
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_file__proc_self_maps=yes \
		ac_cv_file__proc_self_mem=yes

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_SUB=	yes

X11_DESC=	Install PyGTK-based GUI (GameConqueror)
X11_CATEGORIES=	python
X11_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:x11-toolkits/py-gtk2
X11_CONFIGURE_ON=	--enable-gui

post-patch:
	@${REINPLACE_CMD} -e 's,/proc/,/compat/linux&,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's, COPYING,,' ${WRKSRC}/gui/Makefile.in

.include <bsd.port.mk>
