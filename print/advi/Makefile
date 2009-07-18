# New ports collection makefile for:	advi
# Date created:		2006-08-13
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	advi
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Active-DVI viewer

BUILD_DEPENDS=	${CI_DEPEND}:${PORTSDIR}/graphics/ocaml-images \
		kpsewhich:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	kpsewhich:${PORTSDIR}/print/teTeX-base

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes
USE_GHOSTSCRIPT=yes
USE_XORG=	xpm
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
INSTALL_TARGET=	installopt installman

CI_DEPEND=	${LOCALBASE}/${OCAML_LIBDIR}/camlimages/ci_core.a
MAN1=		advi.1

post-extract:
	@${REINPLACE_CMD} -E \
		-e 's,^(COPTIONS[[:space:]]*=).*,\1-ccopt "${CFLAGS}",' \
		-e 's,^(COPTOPTIONS[[:space:]]*=).*,\1-ccopt "${CFLAGS}",' \
		-e 's,^(X11_INCLUDES[[:space:]]*=).*,\1-I${LOCALBASE}/include,' \
		-e 's,install -m 644,\$${BSD_INSTALL_DATA},' \
		-e 's,install -m 755,\$${BSD_INSTALL_PROGRAM},' \
		-e 's,^LIBRARIES = graphics,LIBRARIES =,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
