# New ports collection makefile for:	 latex2html
# Date created:		3 May 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	latex2html
PORTVERSION=	99.2b8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	brett@peloton.runet.edu

BUILD_DEPENDS=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX \
		${LOCALBASE}/bin/gs:${PORTSDIR}/print/ghostscript55 \
		${LOCALBASE}/bin/anytopnm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL} \
		--disable-gif \
		--libdir=${PREFIX}/share/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for file in FAQ INSTALL LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
