# New ports collection makefile for:	SAINT
# Date created:		27 Jan 2000
# Whom:			Carl Johan Madestrand <calle.madestrand@norrgarden.se>
#
# $FreeBSD$
#

PORTNAME=	saint
PORTVERSION=	3.1.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.wwdsi.com/pub/saint/			\
		http://www.wwdsi.com/saint/downloads/

MAINTAINER=	cj@vallcom.net

BUILD_DEPENDS=	nmap:${PORTSDIR}/security/nmap

USE_PERL5=	yes
MANCOMPRESSED=	no
MAN1=		saint.1
WRKSRC=		${WRKDIR}/saint-3.1.2
GNU_CONFIGURE=	yes
MAKE_ENV=	"LIBS=-lrpcsvc" "XFLAGS=-g -O2   -DSTDC_HEADERS=1 -DGETGROUPS_T=gid_t -DSYS_ERRLIST_DECLARED=1 " "RPCGEN=/usr/bin/rpcgen"
INSTALL_TARGET=	all

pre-install:
		${MKDIR} ${PREFIX}/saint
		${TAR} --directory ${WRKSRC} -cf - . --exclude src --exclude Makefile --exclude Makefile.in --exclude old --exclude config.cache --exclude config.log --exclude config.status --exclude configure --exclude configure.in --exclude install-sh --exclude saint.1 | \
			${TAR} --directory ${PREFIX}/saint -xf -
.if !defined(NOPORTDOCS)
do-install:
		${INSTALL_MAN} ${WRKSRC}/saint.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
