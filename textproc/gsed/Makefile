# New ports collection makefile for:	sed
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	sed
PORTVERSION=	3.02
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	g

MAINTAINER=	clefevre@poboxes.com

#
# Global variables
#

GNU_CONFIGURE=	yes

# sed's configure seems to be buggy !
# CONFIGURE_ARGS=	--program-prefix=g

USE_GMAKE=	yes

.if make(do-install)
# DESTDIR isn't honored. fake it w/ prefix.
MAKE_ARGS=	prefix=${PREFIX}
.endif

MAN1=		gsed.1

#
# Local variables
#

PATCH_SUBDIRS=	. doc lib sed

SAMP_FILES=	dc.sed
SAMP_DIR=	${PREFIX}/share/examples/${PKGBASE}

#
# Post-configure
#

post-configure: patch-makefiles

patch-makefiles:
.for subdir in ${PATCH_SUBDIRS}
	@${PERL} -pi.fbsd -e 's/s,x,x,/s,^,g,/' ${WRKSRC}/${subdir}/Makefile
.endfor

#
# Post-install
#

post-install: install-sample-files

install-sample-files:
	@${MKDIR} ${SAMP_DIR}
.for file in ${SAMP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${SAMP_DIR}/${file}
.endfor

.include <bsd.port.mk>
