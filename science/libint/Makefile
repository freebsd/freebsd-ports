# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libint
DISTVERSIONPREFIX=	release-
DISTVERSION=	1-2-1-15
DISTVERSIONSUFFIX=	-gb349524
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limit:^1

USES=		autoreconf:build gmake libtool
USE_GITHUB=	yes
GH_ACCOUNT=	evaleev
USE_LDCONFIG=	yes
ALL_TARGET=	default

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-cc-optflags="${CFLAGS}" \
		--with-cxx-optflags="${CXXFLAGS}"

OPTIONS_DEFINE=			STATIC # osa@ requested to keep static libs on 2018/08/28
OPTIONS_SUB=			yes
STATIC_CONFIGURE_ENABLE=	static

post-patch:
	@${REINPLACE_CMD} -e 's| -rpath|${LDFLAGS} -rpath|g' \
		${WRKSRC}/src/lib/MakeVars.in

pre-configure:
# Cannot run autoheader so cannot use autoreconf.
	@cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize -c -f \
		&& ${LOCALBASE}/bin/aclocal && ${LOCALBASE}/bin/autoconf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
