# New ports collection makefile for:	leafnode+
# Date created:		19 November 1998
# Whom:			Tom Hukins <tom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	leafnode+
PORTVERSION=	2.15
PORTREVISION=	1
CATEGORIES=	news ipv6
MASTER_SITES=	http://www25.big.jp/~jam/leafnode+/ \
		http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-user offline Usenet news package for small sites

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN8=		checkgroups.8 fetchnews.8 leafnode.8 texpire.8
PKGINSTALL=	${WRKDIR}/INSTALL

LEAFLIBDIR?=	${PREFIX}/lib/leafnode
LEAFSPOOLDIR?=	/var/spool/leafnode
REWRITE=	${SED} -e "s:@LIBDIR@:${LEAFLIBDIR}:g" \
		-e "s:@SPOOLDIR@:${LEAFSPOOLDIR}:g" \
		-e "s:@PREFIX@:${PREFIX}:g"

post-patch:
.for file in Makefile FAQ INSTALL README leafnode.8
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.bak
	@${REWRITE} ${WRKSRC}/${file}.bak > ${WRKSRC}/${file}
.endfor
	@${REWRITE} ${FILESDIR}/INSTALL.in > ${PKGINSTALL}
	@${CHMOD} 755 ${PKGINSTALL}

do-install:
.for file in leafnode fetchnews texpire checkgroups leaftool
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/sbin
.endfor
.for file in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
.for file in Changes FAQ INSTALL README config.example
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
