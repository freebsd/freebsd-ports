# New ports collection makefile for:	sed
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	sed
PORTVERSION=	4.0.3
PKGNAMEPREFIX=	g
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--disable-nls
USE_GMAKE=	yes

MAN1=		gsed.1

# Local variables
#

PATCH_SUBDIRS=	. doc lib sed

SAMP_FILES=	dc.sed
SAMP_DIR=	${PREFIX}/share/examples/${PKGBASE}

# Post-configure
#

post-configure: patch-makefiles

patch-makefiles:
.for subdir in ${PATCH_SUBDIRS}
	@${REINPLACE_CMD} -e 's|s,x,x,|s,^,g,|' ${WRKSRC}/${subdir}/Makefile
.endfor

# Post-install
#

post-install: install-sample-files

install-sample-files:
	@${MKDIR} ${SAMP_DIR}
.for file in ${SAMP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/testsuite/${file} ${SAMP_DIR}/${file}
.endfor

.include <bsd.port.mk>
