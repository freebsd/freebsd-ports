# $FreeBSD$

PORTNAME=	shlock
PORTVERSION=	2.6.3
CATEGORIES=	sysutils
MASTER_SITES=	ISC/inn
DISTNAME=	inn-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create lock files for use in shell scripts

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

ALL_TARGET=	all-lib
CONFIGURE_ARGS=	--disable-shared
CONFIGURE_ENV=	ac_cv_path_PERL="${TRUE}"
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/shlock man/man1/shlock.1.gz

post-build:
	@${DO_MAKE_BUILD} -C ${WRKSRC}/backends shlock

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/backends/shlock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/shlock.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
