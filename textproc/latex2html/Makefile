# New ports collection makefile for:	 latex2html
# Date created:		3 May 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	latex2html
PORTVERSION=	2002.2.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert LaTeX documents to HTML

.include <bsd.port.pre.mk>

# Global variables
#

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

BUILD_DEPENDS=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX \
		${LOCALBASE}/bin/gs:${PORTSDIR}/${GSPORT} \
		${LOCALBASE}/bin/anytopnm:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL} \
		--disable-gif \
		--shlibdir=${DATADIR}

MAN1=	latex2html.1

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

# Local variables
#

DOC_FILES=	FAQ INSTALL LICENSE README

# Inform message
#

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

# Port-patch
#

post-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}

# Post-install
#

post-install: install-docs display-message

install-docs:
	${INSTALL_MAN} ${FILESDIR}/latex2html.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
