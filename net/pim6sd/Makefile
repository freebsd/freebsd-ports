# New ports collection makefile for: pim6-sd
# Date created:  2 Jun 2001
# Whom:   dwcjr
#
# $FreeBSD$
#

PORTNAME=	pim6sd
PORTVERSION=	20010602a
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	ume@freebsd.org

MAN5=		pim6sd.conf.5
MAN8=		pim6sd.8
MANCOMPRESSED=	yes

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
.for file in Makefile.inc pim6sd/pathnames.h pim6sd/pim6sd.8
	@${PERL} -pi.orig -e 's./usr/local/v6.${PREFIX}.g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
