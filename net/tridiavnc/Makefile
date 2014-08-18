# Created by: dwcjr
# $FreeBSD$

PORTNAME=	tridiavnc
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dwcjr
DISTNAME=	DevVNC_unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display X and Win32 desktops on remote X/Win32/Java displays

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/unix/vnc_unixsrc
USES=		imake:noman shebangfix perl5 tar:tgz
SHEBANG_FILES=	vncserver
USE_XORG=	ice sm x11 xaw xext xmu xt xpm
ALL_TARGET=	World
XFREE86_HTML_MAN=	no
MAKE_JOBS_UNSAFE=yes

CONFLICTS=	tightvnc-[0-9]* vnc-[0-9]*

# .ifdef(TRIDIAVNC_BASE)
# PREFIX=${TRIDIAVNC_BASE}
# MAKE_ENV+=	DESTDIR=${TRIDIAVNC_BASE}
# .endif

.include <bsd.port.pre.mk>

.if ${ARCH} != i386
BROKEN=		Does not compile on ${MACHINE_ARCH}
PLIST_SUB+=	XVNC="@comment "
.else
PLIST_SUB+=	XVNC=""
.endif

# XXX Broken under clang
NO_XVNC=	yes

post-patch:
.for file in vncviewer/Imakefile Xvnc/config/cf/vnclibs.def Xvnc/config/cf/Imake.tmpl
	${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/${file}
.endfor
	${REINPLACE_CMD} -i '' -e 's|/usr/local/vnc/classes|${DATADIR}/classes|' \
		${WRKSRC}/vncserver

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
.if !defined(NO_XVNC)
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc \
		${STAGEDIR}${PREFIX}/bin/Xvnc
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer \
		${STAGEDIR}${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd \
		${STAGEDIR}${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect \
		${STAGEDIR}${PREFIX}/bin/vncconnect
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver \
		${STAGEDIR}${PREFIX}/bin/vncserver
# Go install Java classes
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vnc
	${CP} -R ${WRKSRC}/classes ${STAGEDIR}${PREFIX}/share/vnc

.include <bsd.port.post.mk>
