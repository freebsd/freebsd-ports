# New ports collection makefile for:	ysm
# Date created:				May 28, 2002
# Whom:					vampiro
#
# $FreeBSD$
#

PORTNAME=	ysm
PORTVERSION=	7.2.7.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://vampiro.rootshell.ru/pub/warez/ \
		http://vampiro.rootshell.ru/ \
		ftp://ftp.treasury.ru/pub/unix/ \
		http://www.treasury.ru/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ysmv7_2_7_1
EXTRACT_SUFX=	.tgz

MAINTAINER=	vampiro@rootshell.ru

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

MAN1=		ysm.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
