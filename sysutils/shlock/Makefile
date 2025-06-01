PORTNAME=	shlock
PORTVERSION=	2.7.3
CATEGORIES=	sysutils
MASTER_SITES=	ISC/inn
DISTNAME=	inn-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create lock files for use in shell scripts
WWW=		https://www.eyrie.org/~eagle/software/inn/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--disable-shared
CONFIGURE_ENV=	ac_cv_path_PERL="${TRUE}"
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/shlock \
		share/man/man8/shlock.8.gz

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/include all
	${DO_MAKE_BUILD} -C ${WRKSRC}/lib all
	${DO_MAKE_BUILD} -C ${WRKSRC}/backends shlock

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/backends/shlock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/shlock.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
