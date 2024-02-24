PORTNAME=	orpie
PORTVERSION=	1.5.2
PORTREVISION=	9
CATEGORIES+=	math
MASTER_SITES=	https://github.com/pelzlpj/orpie/releases/download/release-${PORTVERSION}/

MAINTAINER=	mt-bugs@markoturk.info
COMMENT=	Fullscreen RPN calculator for the console
WWW=		https://pessimization.com/software/orpie/

LICENSE=	GPLv2

NOT_FOR_ARCHS=		armv6 armv7
NOT_FOR_ARCHS_REASON=	architectures with double-word alignment for doubles are not supported

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/num/META:math/ocaml-num
LIB_DEPENDS=	libgsl.so:math/gsl

USES=		gmake ncurses
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/orpie bin/orpie-curses-keys etc/orpierc \
		share/man/man1/orpie.1.gz share/man/man1/orpie-curses-keys.1.gz \
		share/man/man5/orpierc.5.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
