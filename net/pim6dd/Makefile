# New ports collection makefile for: pim6-sd
# Date created:  2 Jun 2001
# Whom:   dwcjr
#
# $FreeBSD$
#

PORTNAME=	pim6dd
PORTVERSION=	20010602a
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	ume@FreeBSD.org

MAN5=		pim6dd.conf.5
MAN8=		pim6dd.8
MANCOMPRESSED=	yes

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
.for file in Makefile.inc pim6dd/pathnames.h pim6dd/pim6dd.8
	@${PERL} -pi.orig -e 's./usr/local/v6.${PREFIX}.g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
