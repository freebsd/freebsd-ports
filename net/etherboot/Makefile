# New ports collection makefile for:   etherboot
# Version required:    4.1
# Date created:        16 April 1999
# Whom:                Doug Ambrisko <ambrisko@whistle.com>
#
# $Id$
#

DISTNAME=	etherboot-4.1
CATEGORIES=	net
MASTER_SITES=   http://www.slug.org.au/etherboot/
#DISTFILES=	etherboot-4.1pre9.tar.bz2
EXTRACT_SUFX=   pre9.tar.bz2

MAINTAINER=	ambrisko@whistle.com

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2 \
		${PREFIX}/bin/as86:${PORTSDIR}/devel/bcc

EXTRACT_CMD=		bzip2 -d <
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| tar xf -

USE_GMAKE=1	# note uses is from emulation package
WRKSRC=		${WRKDIR}/${DISTNAME}/src-32

.include <bsd.port.mk>
