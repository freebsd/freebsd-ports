# New ports collection makefile for:	textproc/mdocml
# Date created:				09.03.2009
# Whom:					Ulrich Spoerlein <uspoerlein@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mdocml
PORTVERSION=	1.10.1
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/ \
		http://people.freebsd.org/~uqs/distfiles/

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	mdoc macro compiler

MAN1=	mandoc.1
MAN7=	man.7 mdoc.7 roff.7 mandoc_char.7

PLIST_SUB+=	EXAMPLESDIR=share/examples/mandoc

post-patch:
	${REINPLACE_CMD} '/^PREFIX/s/=/?=/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
