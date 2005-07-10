# New ports collection makefile for:	pcnfsd
# Date created:		Oct 6, 1994
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	pcnfsd
PORTVERSION=	93.02.16
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tux.org/pub/net/lprng/TOOLS/PCNFSD/ \
		http://lprng.sourceforge.net/DISTRIB/TOOLS/PCNFSD/ \
		http://public.planetmirror.com/pub/lprng/UNIXTOOLS/PCNFSD/
DISTNAME=	pcnfsd.93.02.16
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sun PC NFS authentication and printing server

MAN8=		pcnfsd.8
MANCOMPRESSED=	maybe
PLIST_FILES=	libexec/rpc.pcnfsd

NO_WRKSUBDIR=

post-extract:
	${CP} ${FILESDIR}/Makefile.inc ${WRKSRC}

.include <bsd.port.mk>
