# New ports collection makefile for:	binkd
# Version required:			0.9.2
# Date created:				19 August 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/12/24 06:55:54 steve Exp $
#

DISTNAME=		binkd092
PKGNAME=		binkd-0.9.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.sut.ru/pub/FidoNet/BinkD/092/ \
			ftp://ftp.aanet.ru/pub/Linux/system/Fido/
EXTRACT_SUFX=		.zip

MAINTAINER=		andy@icc.surw.chel.su

BUILD_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip

WRKSRC=			${WRKDIR}/${PKGNAME}
EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
GNU_CONFIGURE=		yes
MAN8=			binkd.8

post-extract:
	@ ${CP} ${WRKSRC}/mkfls/unix/* ${WRKSRC}
	@ chmod a+x ${WRKSRC}/configure

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/binkd ${PREFIX}/sbin
	@ ${INSTALL_MAN} ${WRKSRC}/binkd.8 ${PREFIX}/man/man8
	@ ${INSTALL_DATA} ${WRKSRC}/binkd.cfg ${PREFIX}/etc/binkd.cfg.sample
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/binkd
	@ ${INSTALL_DATA} ${WRKSRC}/!README ${PREFIX}/share/doc/binkd/README
	@ ${INSTALL_DATA} ${WRKSRC}/!README.FIX ${PREFIX}/share/doc/binkd/README.FIX
	@ ${INSTALL_DATA} ${WRKSRC}/!SRIF.TXT ${PREFIX}/share/doc/binkd/SRIF.TXT
	@ ${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/binkd
.endif

.include <bsd.port.mk>
