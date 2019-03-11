# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	gemini
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.brama.com/compute/unix/
PKGNAMEPREFIX=	koi8-u-
PKGNAMESUFFIX=	-x11
DISTNAME=	x-koi8u

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Ukrainian KOI8 fonts for X11R6 (koi8-u)

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontscale>=0:x11-fonts/mkfontscale

USES=		fonts perl5 tar:tgz
USE_PERL5=	build
USE_XORG=	x11
NO_WRKSUBDIR=	yes
FONTNAME=	koi8-u-gemini

post-patch:
	${REINPLACE_CMD} -e 's/\.Z/.gz/g' \
	    -e 's|DESTDIR =.*|MDESTDIR=${STAGEDIR}${FONTSDIR}|' \
	${WRKSRC}/Makefile

# This will  allow one to  use just this  fonts for both,  the Ukrainian
# koi8-u and the Russian koi8-r encodings. Since koi8-u is a superset of
# koi8-r, there  is not need to  load both sets into  X-server, but some
# applications look for cronyx-*-koi8-r or koi8-r explicitly.	-mi
post-build:
	# Creating aliases for koi8-r encoding and Cronyx foundry:
	@${ECHO_CMD} >> ${WRKSRC}/fonts.alias
	@${ECHO_CMD} "! Automaticly generated aliases for koi8-r encoding:" \
		>> ${WRKSRC}/fonts.alias
	${AWK} '/gemini/ { \
		name = $$2; \
		gsub("koi8-u", "koi8-r", $$2); \
		print $$2 " " name; \
		gsub("gemini", "cronyx", $$2); \
		print $$2 " " name; \
	}' < ${WRKSRC}/fonts.dir >> ${WRKSRC}/fonts.alias

pre-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
