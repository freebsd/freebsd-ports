# New ports collection makefile for:	dgd-net
# Date created:		17 June 1996
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	dgd-net
PORTVERSION=	1.1.8
CATEGORIES=	net lang
MASTER_SITES=	ftp://ftp.dworkin.nl/pub/dgd/archive/ \
		http://dl.droso.net/ports/
DISTFILES=	dgd-1.1p8.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dworkin's Generic Driver + extra networking support + regexps

NO_CDROM=	"no distribution to corporate environment"
RESTRICTED=	"license required for commercial use"

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=	-d ${WRKDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=	-d ${WRKDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

pre-patch:
	@${LN} -s dgd ${WRKDIR}/dgd+net
	@${MKDIR} ${WRKDIR}/dgd/bin

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@${MV} ${WRKDIR}/dgd/bin/driver ${WRKDIR}/dgd/bin/driver.net
	@${MV} ${WRKDIR}/dgd/bin/precomp ${WRKDIR}/dgd/bin/precomp.net
	@${MV} ${WRKDIR}/dgd/doc/Introduction ${WRKDIR}/dgd/doc/Introduction.NET
	@${MV} ${WRKDIR}/dgd/doc/kfun/send_message ${WRKDIR}/dgd/doc/kfun/send_message.NET
	@${CHMOD} o+r ${WRKDIR}/dgd/doc/kfun/*

do-install:
	@-${MV} ${PREFIX}/dgd/bin/driver.net ${PREFIX}/dgd/bin/driver.net.old
	@${TAR} -C ${WRKDIR} -cf - `${GREP} '^dgd/' ${PLIST}` \
		| ${TAR} -C ${PREFIX} -xpf -

.include <bsd.port.post.mk>
