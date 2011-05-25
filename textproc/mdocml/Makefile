# New ports collection makefile for:	textproc/mdocml
# Date created:				09.03.2009
# Whom:					Ulrich Spoerlein <uspoerlein@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mdocml
PORTVERSION=	1.11.2
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	mdoc macro compiler

MAN1=	mandoc.1
MAN3=	mandoc.3
MAN7=	eqn.7 man.7 mandoc_char.7 mdoc.7 roff.7 tbl.7

EXAMPLESDIR_REL=share/examples/mandoc

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s/-g//' -e '/^PREFIX/s/=/?=/' \
		-e '/INSTALL_LIB/d' -e '/LIBDIR/d' -e '/INCLUDEDIR/d' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
