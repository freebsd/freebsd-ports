# New ports collection makefile for:	SAINT
# Date created:		27 Jan 2000
# Whom:			Carl Johan Madestrand <calle.madestrand@norrgarden.se>
#
# $FreeBSD$
#

PORTNAME=	saint
PORTVERSION=	3.5.8
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Security Administrator's Integrated Network Tool

BUILD_DEPENDS=	nmap:${PORTSDIR}/security/nmap
.if defined(WITH_SAMBA)
BUILD_DEPENDS+=	smbclient:${PORTSDIR}/net/samba
.endif

USE_PERL5=	yes
MANCOMPRESSED=	no
MAN1=		saint.1
GNU_CONFIGURE=	yes
MAKE_ENV=	"LIBS=-lrpcsvc" "XFLAGS=-g -O2   -DSTDC_HEADERS=1 -DGETGROUPS_T=gid_t -DSYS_ERRLIST_DECLARED=1 " "RPCGEN=/usr/bin/rpcgen"
INSTALL_TARGET=	all

DOWNLOAD_URL?=	http://www.wwdsi.com/products/download.html

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		You must manually fetch the source distribution (${DISTFILES}) \
	from ${DOWNLOAD_URL}, choose SAINT - Free Trial, place it in \
	${DISTDIR} and then run make again
.endif
NO_CDROM=	yes

pre-install:
		${MKDIR} ${PREFIX}/saint
		${TAR} --directory ${WRKSRC} -cf - . --exclude src --exclude Makefile --exclude Makefile.in --exclude old --exclude config.cache --exclude config.log --exclude config.status --exclude configure --exclude configure.in --exclude install-sh --exclude saint.1 | \
			${TAR} --directory ${PREFIX}/saint -xf -
.if !defined(NOPORTDOCS)
do-install:
		${INSTALL_MAN} ${WRKSRC}/saint.1 ${PREFIX}/man/man1
.endif

post-install:
		${RM} -rf ${PREFIX}/saint/include/ASM-i386

.include <bsd.port.post.mk>
