# Created by: ache
# $FreeBSD$

PORTNAME=	WebMagick
PORTVERSION=	2.03p29
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www graphics
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}-beta/${DISTVERSION}
DISTNAME=	${PORTNAME}-2.03pre29

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image Web Generator - recursively build HTMLs, imagemaps, thumbnails

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libMagickCore-6.so:graphics/ImageMagick
RUN_DEPENDS=	p5-Sort-Naturally>=0:textproc/p5-Sort-Naturally

USES=		shebangfix perl5 autoreconf
GNU_CONFIGURE=	yes
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

OPTIONS_DEFINE=		X11
X11_BUILD_DEPENDS=	xlsfonts:x11-fonts/xlsfonts
X11_RUN_DEPENDS=	xlsfonts:x11-fonts/xlsfonts
X11_CONFIGURE_ENV_OFF=	with_x=no

.include <bsd.port.pre.mk>

pre-configure:
	@if [ ! -f ${SITE_ARCH}/Image/Magick.pm ]; then \
		${ECHO_CMD} ERROR: ImageMagick must be installed with the PERL option enabled; \
		${FALSE}; \
	fi

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/data

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/webmagickrc.dist \
		${STAGEDIR}${PREFIX}/etc/webmagickrc.sample

.include <bsd.port.post.mk>
