# New ports collection makefile for:    pmf
# Version required:     1.13.1
# Date created:         24 Sep 1994
# Whom:                 adam
#
# $Id: Makefile,v 1.3 1994/09/25 19:43:30 adam Exp $
#

DISTNAME=       pmf-1.13.1
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/clients/
CATEGORIES+=	networking
WRKSRC=		${WRKDIR}/pmfdir/src

pre-install:
	@mkdir -p /usr/local/lib/pmf
	@find ${WRKSRC}/../system_dir -name '*.orig' -exec rm {} \;
	@-mv ${WRKSRC}/../doc/pmf.doc ${WRKSRC}/../system_dir
	@tar -C ${WRKSRC}/../system_dir -cf - . \
		| tar -C /usr/local/lib/pmf -xf -
	@chown -R bin.bin /usr/local/lib/pmf
	@chmod -R a-w /usr/local/lib/pmf

.include <bsd.port.mk>
