PORTNAME=	gv
PORTVERSION=	3.7.4
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	GNU

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	PostScript and PDF previewer
WWW=		https://www.gnu.org/software/gv/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/libXaw3d

USES=		cpe ghostscript:x11 iconv gmake localbase perl5 pkgconfig \
		shebangfix xorg
USE_PERL5=	build
USE_XORG=	ice sm x11 xext xinerama xmu xpm xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/X11 \
			--enable-setenv-code \
			--enable-SIGCHLD-fallback \
			ac_cv_lib_iconv_iconv_open=no
SHEBANG_FILES=	${WRKSRC}/src/gv-update-userconfig.in

INFO=		gv
CPE_VENDOR=	gnu
PLIST_FILES=	bin/gv \
		bin/gv-update-userconfig \
		${DATADIR}/gv_system.ad \
		lib/X11/app-defaults/GV \
		share/man/man1/gv.1.gz \
		share/man/man1/gv-update-userconfig.1.gz
PLIST_DIRS=	${DATADIR}/safe-gs-workdir

.include <bsd.port.mk>
