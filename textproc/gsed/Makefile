# New ports collection makefile for:	sed
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	sed
PORTVERSION=	4.0.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	g

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	The GNU stream editor

# Global variables
#

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--disable-nls
USE_GMAKE=	yes

INFO=		sed
MAN1=		gsed.1

# Local variables
#

PATCH_SUBDIRS=	. doc lib sed
DATADIR=	${PREFIX}/share/${PKGBASE}

SAMP_FILES=	binary*.sed dc.sed
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

DOC_FILES=	AUTHORS BUGS COPYING COPYING.DOC NEWS README THANKS
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

# Post-configure
#

post-configure: patch-makefiles

patch-makefiles:
.for subdir in ${PATCH_SUBDIRS}
	@${REINPLACE_CMD} -e 's|s,x,x,|s,^,g,|' ${WRKSRC}/${subdir}/Makefile
.endfor

# Post-install
#

post-install: install-sample-files install-doc-files

install-sample-files:
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${SAMP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/testsuite/${file} ${EXAMPLESDIR}
.endfor

install-doc-files:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

# Maintainer only
#
test:
	@cd ${WRKSRC}/testsuite; ${MAKE} check

.include <bsd.port.mk>
