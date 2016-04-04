# Created by: tg@FreeBSD.org
# $FreeBSD$

PORTNAME=	gv
PORTVERSION=	3.7.4
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	GNU/${PORTNAME}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	PostScript and PDF previewer

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

USE_XORG=	xpm ice sm xext xmu x11
USES=		cpe ghostscript:x11 iconv gmake perl5 shebangfix
USE_PERL5=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/X11 \
			--enable-setenv-code \
			--enable-SIGCHLD-fallback
SHEBANG_FILES=	${WRKSRC}/src/gv-update-userconfig.in

INFO=		gv
CPE_VENDOR=	gnu
PLIST_FILES=	bin/gv \
		bin/gv-update-userconfig \
		%%DATADIR%%/gv_system.ad \
		lib/X11/app-defaults/GV \
		man/man1/gv.1.gz \
		man/man1/gv-update-userconfig.1.gz
PLIST_DIRS=	%%DATADIR%%/safe-gs-workdir

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv_open=no
.endif

.include <bsd.port.post.mk>
