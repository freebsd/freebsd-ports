PORTNAME=	httping
PORTVERSION=	2.9
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Ping-like tool for HTTP requests
WWW=		https://github.com/folkertvanheusden/HTTPing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gettext-runtime gettext-tools gmake localbase:ldflags ssl \
		tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	folkertvanheusden
GH_PROJECT=	HTTPing

OPTIONS_DEFINE=		FFTW NCURSES NLS
OPTIONS_DEFAULT=	NCURSES
OPTIONS_SUB=		NLS

FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_MAKE_ENV=		FW=yes
FFTW_MAKE_ENV_OFF=	FW=no
NCURSES_USES=		ncurses
NCURSES_MAKE_ENV=	NC=yes
NCURSES_MAKE_ENV_OFF=	NC=yes
NLS_MAKE_ENV_OFF=	NO_GETTEXT=yes

.include <bsd.port.pre.mk>

# DragonFly seems to require this
.if ${OPSYS} == FreeBSD
MAKE_ENV+=	TFO=yes
.endif

post-patch-NCURSES-on:
	@${REINPLACE_CMD} "s/-lncursesw/${NCURSESLIBS}/g" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
