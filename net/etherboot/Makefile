# New ports collection makefile for:   etherboot
# Version required:    4.1
# Date created:        16 April 1999
# Whom:                Doug Ambrisko <ambrisko@whistle.com>
#
# $Id: Makefile,v 1.2 1999/04/18 13:43:01 erich Exp $
#

DISTNAME=	etherboot-4.1pre9
PKGNAME=	etherboot-4.1p9
CATEGORIES=	net
MASTER_SITES=   http://www.slug.org.au/etherboot/

MAINTAINER=	ambrisko@whistle.com

BUILD_DEPENDS=	as86:${PORTSDIR}/devel/bcc

BROKEN=		"4.2 has been released, this port is no longer fetchable"

USE_BZIP2=	yes
USE_GMAKE=1	# note uses is from emulation package
WRKSRC=		${WRKDIR}/${DISTNAME}/src-32

.include <bsd.port.mk>
