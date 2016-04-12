# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	rtfx
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://thewalter.net/stef/software/rtfx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RTF to XML converter

LIB_DEPENDS=	libmba.so:devel/libmba \
		libdomc.so:textproc/domc

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
