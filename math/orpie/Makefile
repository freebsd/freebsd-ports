# Created by: Dylan Simon <dylan@dylex.net>
# $FreeBSD$

PORTNAME=	orpie
PORTVERSION=	1.5.1
PORTREVISION=	6
CATEGORIES+=	math
MASTER_SITES=	http://pessimization.com/software/orpie/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fullscreen RPN calculator for the console

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/orpie bin/orpie-curses-keys etc/orpierc \
		man/man1/orpie.1.gz man/man1/orpie-curses-keys.1.gz \
		man/man5/orpierc.5.gz

.include <bsd.port.mk>
