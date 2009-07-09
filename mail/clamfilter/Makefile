# New ports collection makefile for:    clamfilter
# Date created:        11 Feb 2005
# Whom:                SeaD
#
# $FreeBSD$
#

# Anyone upgrading this port is advised to check all changes since the
# previous tarball; I have updated MASTER_SITES to an alternative
# location, but I have no idea if this is an official mirror or not.
#
# The old site was: http://www.ensita.net/products/clamfilter/

PORTNAME=	clamfilter
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.wyae.de/software/Retired/ensita-clamfilter/

MAINTAINER=	sahil@tandon.net
COMMENT=	A small, efficient clamav content filter for Postfix

.if defined(WITH_CLAMAV_DEVEL)
RUN_DEPENDS=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav-devel
.else
RUN_DEPENDS=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
.endif

SUB_FILES=	pkg-message
PLIST_FILES=	bin/clamfilter

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
