# New ports collection makefile for:    pmf
# Version required:     1.13.1
# Date created:         24 Sep 1994
# Whom:                 adam
#
# $Id: Makefile,v 1.9 1997/04/01 23:49:05 fenner Exp $
#

DISTNAME=       pmf-1.13.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/clients/pmf/

WRKSRC=		${WRKDIR}/pmfdir/src


BROKEN_ELF=	cc: c_packages/libc_packs.a: No such file or directory

pre-install:
	@${MKDIR} /usr/local/lib/pmf
	@find ${WRKSRC}/../system_dir -name '*.orig' -exec rm {} \;
	@-mv ${WRKSRC}/../doc/pmf.doc ${WRKSRC}/../system_dir
	@tar -C ${WRKSRC}/../system_dir -cf - . \
		| tar -C /usr/local/lib/pmf -xf -
	@chown -R bin.bin /usr/local/lib/pmf
	@chmod -R a-w /usr/local/lib/pmf

.include <bsd.port.mk>
