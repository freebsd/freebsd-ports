# New ports collection makefile for:	 latex2html
# Date created:		3 May 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	latex2html
PORTVERSION=	2002.2.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,-,g}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Convert LaTeX documents to HTML

BUILD_DEPENDS=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/bin/anytopnm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=		yes
USE_GHOSTSCRIPT=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=	--with-perl=${PERL} \
		--disable-gif \
		--shlibdir=${DATADIR} \
		--with-texpath=${PREFIX}/${TEXMFLOCAL}/tex/latex/html
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGMESSAGE_IN=	${PKGDIR}/pkg-message
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR}

MAN1=	latex2html.1

TEXMFLOCAL=	share/texmf-local
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
DOC_FILES=	FAQ INSTALL LICENSE README

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE_IN} > ${PKGMESSAGE}

post-install:
	${INSTALL_MAN} ${FILESDIR}/latex2html.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${MKTEXLSR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
