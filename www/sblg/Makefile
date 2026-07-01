PORTNAME=	sblg
DISTVERSION=	0.6.1
CATEGORIES=	www textproc
MASTER_SITES=	https://kristaps.bsd.lv/sblg/snapshots/

MAINTAINER=	nsonack@herrhotzenplotz.de
COMMENT=	Static blog utility
WWW=		https://kristaps.bsd.lv/sblg/

LICENSE=	ISCL

LIB_DEPENDS=	libexpat.so:textproc/expat2
RUN_DEPENDS=	lowdown>2:textproc/lowdown

USES=		pkgconfig

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	MANDIR=${PREFIX}/share/man

MAKE_ARGS=	EXAMPLEDIR=${EXAMPLESDIR}

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sblg

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
