# Ports collection makefile for:  sar
# http://tarp.linuxos.org/software/
# Version required:               0.2
# Date created:                   Feb 18, 1999
# Whom:                           ache
#
# $FreeBSD$
#

DISTNAME=       sar
PKGNAME=        sar-0.2
CATEGORIES=	textproc
MASTER_SITES=   http://tarp.linuxos.org/software/
EXTRACT_SUFX=

MAINTAINER=     ache@freebsd.org

EXTRACT_CMD=    $(CP)
EXTRACT_BEFORE_ARGS=    # empty
EXTRACT_AFTER_ARGS= ${WRKSRC}

NO_BUILD=       YES
NO_WRKSUBDIR=   yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sar ${PREFIX}/bin

.include <bsd.port.mk>
