# New ports collection makefile for:	 latex2html
# Date created:		3 May 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	latex2html
PORTVERSION=	2002-2-1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.pre.mk>

# Global variables
#

BUILD_DEPENDS=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX \
		${LOCALBASE}/bin/gs:${PORTSDIR}/print/ghostscript-gnu \
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

# Port-patch
#

post-patch: patch-message

patch-message:
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
