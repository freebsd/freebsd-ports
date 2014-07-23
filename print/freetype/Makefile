# Created by: jseger@FreeBSD.org
# $FreeBSD$

PORTNAME=	freetype
PORTVERSION=	1.3.1
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	SF \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype1/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype1/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype1/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/freetype/freetupe1/

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Free and portable TrueType font rendering engine

USES=		desthack libtool:oldver
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared

PORTSCOUT=	limit:^1\.

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

# Older versions of freetype installed include files in ${PREFIX}/include
# this is a compatibility hack for now

#post-install:
#	${LN} -fs ${PREFIX}/include/freetype/*.h ${PREFIX}/include

.include <bsd.port.mk>
