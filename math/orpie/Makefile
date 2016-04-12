# Created by: Dylan Simon <dylan@dylex.net>
# $FreeBSD$

PORTNAME=	orpie
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES+=	math
MASTER_SITES=	http://pessimization.com/software/orpie/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fullscreen RPN calculator for the console

LICENSE=	GPLv2

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		gmake ncurses
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/orpie bin/orpie-curses-keys etc/orpierc \
		man/man1/orpie.1.gz man/man1/orpie-curses-keys.1.gz \
		man/man5/orpierc.5.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
