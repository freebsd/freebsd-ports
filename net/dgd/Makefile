# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.2p3
CATEGORIES=	net lang
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd|} \
		ftp://ftp.dworkin.nl/pub/dgd/ \
		ftp://ftp.imaginary.com/pub/LPC/servers/DGD/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dworkin's Generic Driver (network server)

NO_CDROM=	"no distribution to corporate environment"
RESTRICTED=	"license required for commercial use"

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
ALL_TARGET=	install

do-install:
	@${TAR} -C ${WRKDIR} -cf - `${GREP} '^dgd/' ${PLIST}` \
		| ${TAR} -C ${PREFIX} -xpf -

.include <bsd.port.mk>
