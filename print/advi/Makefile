# New ports collection makefile for:	advi
# Date created:		2006-08-13
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	advi
PORTVERSION=	1.9
PORTREVISION=	0
CATEGORIES=	print
MASTER_SITES=	http://gallium.inria.fr/${PORTNAME}/ \
		http://caml.inria.fr/distrib/bazar-ocaml/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Active-DVI viewer

BUILD_DEPENDS=	${CI_DEPEND}:${PORTSDIR}/graphics/ocaml-images \
		kpsewhich:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	kpsewhich:${PORTSDIR}/print/teTeX-base

USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
NO_OCAML_RUNDEPENDS=yes
GNU_CONFIGURE=yes
USE_XORG=	xpm
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-bytecode-program

OPTIONS=	GS "Enable Ghostscript support" on

CI_DEPEND=	${LOCALBASE}/${OCAML_LIBDIR}/site-lib/camlimages/camlimages.a
MAN1=		advi.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GS)
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-GS=maybe
.else
CONFIGURE_ARGS+=	--with-GS=no
.endif

pre-everything::
	@${ECHO} "************************************************************"
	@${ECHO} "ATTENTION!  This port required ocaml-images to be built with"
	@${ECHO} "Ghostscript support enabled.  If you build graphics/ocaml-images"
	@${ECHO} "without GS support, please rebuild it before building this port"
	@${ECHO} "************************************************************"
	@${ECHO}

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E \
		-e 's,(SUBDIRS[[:space:]]*=[[:space:]]*src[[:space:]]+tex[[:space:]]+)doc,\1,g' \
		${WRKSRC}/Makefile.in
.endif

post-install:
#
# Install manpage by hand
#
.if defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/doc/advi.1 ${MANPREFIX}/man/man1/
.endif

.include <bsd.port.mk>
