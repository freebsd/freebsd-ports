# New ports collection makefile for:	findutils
# Date created:				29 March 2000
# Whom:					Robert Withrow <witr@rwwa.com>
#
# $FreeBSD$
#

PORTNAME=	findutils
PORTVERSION=	4.1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= findutils

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	The GNU find utilities

# Global variables
#

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--program-prefix=g # --localstatedir=${LOCALSTATEDIR}
MAKE_ARGS=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

MAN1=		gfind.1 gxargs.1 glocate.1 gupdatedb.1
MAN5=		glocatedb.5

# Local variables
#

LOCALSTATEDIR?=	/var/db

INSTALL_INFO?=	install-info

# Post-extract
#

post-extract:
	@${RM} -f ${WRKSRC}/doc/${PORTNAME:S/utils//}.info*

# Post-patch
#

post-patch:
	@${REINPLACE_CMD} -e 's|makeinfo|makeinfo --no-split|g' \
		${WRKSRC}/doc/Makefile.in

# Post-configure
#

# --localstatedir= isn't handled right now, so, do it manually.
post-configure:
	@${REINPLACE_CMD} -e 's|\$$\(prefix\)/var|${LOCALSTATEDIR}|g' \
		${WRKSRC}/Makefile ${WRKSRC}/locate/Makefile

# Post-install
#

post-install: install-info remove-catman

install-info:
	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME:S/utils//}.info ${PREFIX}/info/dir

remove-catman:
.for mansect in 1 5
.for man in ${MAN${mansect}}
	@${RM} -f ${MAN1PREFIX}/man/cat${mansect}/${man}
.endfor
.endfor

.include <bsd.port.mk>
