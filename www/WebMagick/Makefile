# Created by: ache
# $FreeBSD$

PORTNAME=	WebMagick
PORTVERSION=	2.03p25
DISTVERSION=	2.03pre25
PORTEPOCH=	1
CATEGORIES=	www graphics
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}-beta/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Web Generator - recursively build HTMLs, imagemaps, thumbnails

LICENSE=	GPLv2

LIB_DEPENDS=	libMagickCore-6.Q*.so:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	p5-Sort-Naturally>=0:${PORTSDIR}/textproc/p5-Sort-Naturally

USES=		shebangfix perl5
USE_AUTOTOOLS=  autoconf aclocal automake
AUTOMAKE_ARGS+= --add-missing
INFO=		webmagick
MAKE_ARGS+=	ICON_INSTALL_DIR=${STAGEDIR}${PREFIX}/www/data/webmagick \
		ETC_INSTALL_DIR=${STAGEDIR}${PREFIX}/etc
CONFIGURE_ENV+=	webmagick_cv_rootpath=${PREFIX}/www/data \
		webmagick_cv_iconpath=webmagick \
		webmagick_cv_prefixpath="" \
		webmagick_cv_htimage="" \
		webmagick_cv_maptype=ncsa \
		PERL=${PERL}
SHEBANG_FILES=	utils/aub \
		utils/aub_hook \
		utils/help2man \
		utils/make_dir_index.pl

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/bin/xlsfonts)
WITHOUT_X11=	yes
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ENV+=with_x=no
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/data

.include <bsd.port.post.mk>
