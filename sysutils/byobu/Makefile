# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	byobu
PORTVERSION=	5.133
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	jcoffman@xsecure.io
COMMENT=	Profile and configuration utilities for GNU Screen and/or tmux

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed

USES=		autoreconf python shebangfix

SHEBANG_FILES=	usr/lib/byobu/include/notify_osd \
		usr/lib/byobu/include/config.py.in \
		usr/lib/byobu/include/select-session.py

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS NEWT

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	TMUX SCREEN

OPTIONS_DEFAULT=	DOCS NEWT TMUX

NEWT_DESC=	Python-based windowing toolkit (required for config menu)
NEWT_LIB_DEPENDS=	libnewt.so:devel/newt

TMUX_DESC=	Terminal Multiplexer (byobu default)
TMUX_RUN_DEPENDS=	tmux:sysutils/tmux

SCREEN_DESC=	Multi-screen window manager
SCREEN_RUN_DEPENDS=	screen:sysutils/screen

NO_ARCH=	yes

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
		${REINPLACE_CMD} \
			-e "s@/bin/bash@${LOCALBASE}/bin/bash@" \
			-e "s@/usr/bin/python@${PYTHON_CMD}@"
	${REINPLACE_CMD} -e 's,@sysconfdir@/profile.d,$$(datadir)/@PACKAGE@,' \
		${WRKSRC}/etc/profile.d/Makefile.am
	${FIND} ${WRKSRC}/usr/lib/byobu -type f -maxdepth 1 | ${XARGS} \
		${REINPLACE_CMD} -e 's:/proc:/compat/linux/proc:g'

.include <bsd.port.mk>
