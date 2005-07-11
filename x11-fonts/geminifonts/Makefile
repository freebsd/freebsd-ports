# New ports collection makefile for:	koi8rPS
# Date created:				Oct 30, 2000
# Whom:					mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	gemini
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.brama.com/compute/unix/
PKGNAMEPREFIX=	koi8-u-
PKGNAMESUFFIX=	-x11
DISTNAME=	x-koi8u
EXTRACT_SUFX=	.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Ukrainian KOI8 fonts for X11R6 (koi8-u)

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}

USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes

MAKE_ENV+=	DESTDIR=${X11BASE}/lib/X11/fonts/koi8-u-gemini
MAKE_ARGS+=	-E DESTDIR -j 2

post-patch:
	${PERL} -pi -e 's/\.Z/.gz/g' ${WRKSRC}/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

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

.include <bsd.port.mk>
