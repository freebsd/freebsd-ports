# Ports collection makefile for:  sar
# http://tarp.linuxos.org/software/
# Version required:               0.2
#
# $Id: Makefile,v 1.2 1999/02/18 17:51:40 ache Exp $
#

DISTNAME=       sar
PKGNAME=        sar-0.2
CATEGORIES=	textproc
MASTER_SITES=   http://tarp.linuxos.org/software/
EXTRACT_SUFX=

MAINTAINER=     ache@freebsd.org

EXTRACT_ONLY=
NO_BUILD=       YES

do-install:
	@${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
