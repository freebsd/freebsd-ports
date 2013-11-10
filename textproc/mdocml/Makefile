# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	mdocml
PORTVERSION=	1.12.2
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	mdoc macro compiler

EXAMPLESDIR_REL=share/examples/mandoc

# Skip installing preconv(1) to avoid conflicting with textproc/groff
post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s/-g//' -e '/^PREFIX/s/=/?=/' \
		-e '/INSTALL_LIB/d' -e '/LIBDIR/d' -e '/INCLUDEDIR/d' \
		-e '/INSTALL_/s/preconv\(\.1\)*//' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
