# New ports collection makefile for:    rprint
# Date created:         June 19th, 2001
# Whom:                 Konrad Heuer
#
# $FreeBSD$
#

PORTNAME=	rprint
PORTVERSION=	3.2
CATEGORIES=	print
MASTER_SITES=	ftp://gwdu60.gwdg.de/pub/FreeBSD/misc/ \
		ftp://gwdu61.gwdg.de/pub/FreeBSD/misc/

MAINTAINER=	kheuer@gwdu60.gwdg.de

MAN1=		rprint.1
MANCOMPRESSED=	yes

post-patch:
	@${PERL} -pi -e "s/^(CC|CFLAGS).+//g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
