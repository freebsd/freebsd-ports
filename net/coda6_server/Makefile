# Created by: Tim Robbins
# $FreeBSD$

PORTNAME=	coda
PORTVERSION=	6.9.4
PORTREVISION?=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/
PKGNAMESUFFIX=	-${CODA_SUITE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server programs for a replicated high-performance network file system

LIB_DEPENDS=	liblwp.so:devel/lwp \
		librpc2.so:devel/rpc2 \
		librvmlwp.so:devel/rvm

USES=		pkgconfig gmake shebangfix perl5 readline
USE_PERL5=	run
SHEBANG_FILES=	coda-src/scripts/tape.pl \
		coda-src/scripts/volinfo.pl \
		coda-src/scripts/volsizes.pl \
		coda-src/scripts/volmunge
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-${CODA_SUITE}
CODA_SUITE?=	server

.if ${CODA_SUITE} == server
CONFLICTS=	openafs-[0-9]*
.endif

.include <bsd.port.pre.mk>

.if ${CODA_SUITE} == client
# this needs testing with the new version (6.1.1)
#IGNORE=	makes a kernel panic on this version of FreeBSD
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "WARNING:"
	@${ECHO_CMD} "This version ${PORTVERSION} of the coda client has not been tested at all under FreeBSD."
	@${ECHO_CMD} "Previous version 6.0.7 was known to cause a kernel panic."
	@${ECHO_CMD} "If you make some tests, please send the results to ports@FreeBSD.org"
	@${ECHO_CMD} ""
.endif

.include <bsd.port.post.mk>
