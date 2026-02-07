PORTNAME=	oils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.34.0
CATEGORIES=	shells
MASTER_SITES=	https://oils.pub/download/
PKGNAMESUFFIX=	-shell
DISTNAME=	oils-for-unix-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	New Unix shell
WWW=		https://www.oils.pub/ \
		https://github.com/oils-for-unix/oils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake

OPTIONS_DEFINE=			READLINE LIBC-FEAT SYSTEMTAP-SDT
OPTIONS_DEFAULT=		READLINE LIBC-FEAT SYSTEMTAP-SDT

READLINE_DESC=			Enable use of GNU readline
LIBC-FEAT_DESC=			Assume FNM_EXTMATCH, GLOB_PERIOD, *pwent()
SYSTEMTAP-SDT_DESC=		Compile with systemtap-sdt

READLINE_LIB_DEPENDS=		libreadline.so:devel/readline
READLINE_CONFIGURE_WITH=	readline
READLINE_CONFIGURE_ON=		--readline=${LOCALBASE}

LIBC-FEAT_CONFIGURE_WITH=	libc-features

SYSTEMTAP-SDT_CONFIGURE_WITH=	systemtap-sdt

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/oils-for-unix \
		bin/osh \
		bin/ysh \
		share/man/man1/osh.1.gz

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} _build/oils.sh
do-install:
	@cd ${WRKSRC} && \
		${SETENV} DESTDIR=${STAGEDIR} ./install

.include <bsd.port.mk>
