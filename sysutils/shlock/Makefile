# $FreeBSD$

PORTNAME=	shlock
PORTVERSION=	2.6.0
CATEGORIES=	sysutils
MASTER_SITES=	ISC/inn
DISTFILES=	inn-${PORTVERSION}${EXTRACT_SUFX} \
		inn-${PORTVERSION}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	inn-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create lock files for use in shell scripts

WRKSRC=		${WRKDIR}/inn-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_PERL="${TRUE}"
CONFIGURE_ARGS=	--disable-shared
ALL_TARGET=	all-lib

PLIST_FILES=	bin/shlock man/man1/shlock.1.gz

verify:	checksum
	gpg --verify ${DISTDIR}/inn-${PORTVERSION}${EXTRACT_SUFX}.asc

post-patch:
	@${REINPLACE_CMD} -e \
		'/#pragma GCC/s|^|// |' ${WRKSRC}/lib/getmodaddr.c

post-build:
	@(cd ${WRKSRC}/backends && ${DO_MAKE_BUILD} shlock)

do-install:
	(cd ${WRKSRC}/backends && ${WRKSRC}/libtool --mode=install \
		${INSTALL_PROGRAM} shlock ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc/man && ${INSTALL_MAN} shlock.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
