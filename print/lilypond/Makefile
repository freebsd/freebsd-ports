# New ports collection makefile for:	lilypond
# Date created:				2001-02-10
# Whom:					trevor
# based on NetBSD pkgsrc/print/lilypond
#
# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 17:32:11 rh Exp $
# $FreeBSD$
#

PORTNAME=	lilypond
PORTVERSION=	1.6.0
CATEGORIES=	print audio
MASTER_SITES=	ftp://ftp.cs.uu.nl/pub/GNU/LilyPond/v1.6/ \
		ftp://sca.uwaterloo.ca/pub/lilypond/v1.6/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	The GNU music typesetter

BUILD_DEPENDS=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

MAN1=	abc2ly.1 as2text.1 convert-ly.1 etf2ly.1 lilypond.1 \
	lilypond-book.1 ly2dvi.1 midi2ly.1 mup2ly.1 musedata2ly.1 pmx2ly.1

GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	YES
USE_PYTHON=	YES
USE_GCC=	2.95
USE_REINPLACE=	yes
MAKEFILE=	GNUmakefile

INFO_FILES=		lilypond.info lilypond-internals.info
CONFIGURE_ARGS+=	--with-kpathsea-include=${PREFIX}/include \
			--with-kpathsea-lib=${PREFIX}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Configure fails"
.endif

post-configure:
	${REINPLACE_CMD} -e "s:^INFO_FILES:xxxINFO_FILES:g" \
		${WRKSRC}/Documentation/user/GNUmakefile

post-install:
	@cd ${WRKSRC}/input ; \
	${MKDIR} ${PREFIX}/share/examples/lilypond ;\
	${TAR} -chf - . | ${TAR} -xf - -C ${PREFIX}/share/examples/lilypond ;\
	${FIND} ${PREFIX}/share/examples/lilypond -name "GNUmakefile" | xargs ${RM} ;\
	${FIND} ${PREFIX}/share/examples/lilypond -name "out" | xargs ${RM} -rf ;\

.include <bsd.port.post.mk>
