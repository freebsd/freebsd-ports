# Created by: tg@FreeBSD.org
# $FreeBSD$

PORTNAME=	gv
PORTVERSION=	3.7.4
CATEGORIES=	print
MASTER_SITES=	GNU/${PORTNAME}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	PostScript and PDF previewer

LIB_DEPENDS=	libXaw3d.so:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XORG=	xpm ice sm xext xmu x11
USE_GHOSTSCRIPT=	yes
USES=		iconv gmake perl5 shebangfix
USE_PERL5=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/X11 \
			--enable-setenv-code \
			--enable-SIGCHLD-fallback
SHEBANG_FILES=	${WRKSRC}/src/gv-update-userconfig.in

INFO=		gv
PLIST_FILES=	bin/gv \
		bin/gv-update-userconfig \
		%%DATADIR%%/gv_system.ad \
		%%DATADIR%%/safe-gs-workdir/.keep_me \
		lib/X11/app-defaults/GV \
		man/man1/gv.1.gz \
		man/man1/gv-update-userconfig.1.gz
PLIST_DIRS=	%%DATADIR%%/safe-gs-workdir \
		%%DATADIR%%

post-install:
	@${TOUCH} ${STAGEDIR}${DATADIR}/safe-gs-workdir/.keep_me

.include <bsd.port.mk>
