# $FreeBSD$

PORTNAME=	shlock
PORTVERSION=	2.5.3
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
ALL_TARGET=	all-lib

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

verify:	checksum
	gpg --verify ${DISTDIR}/inn-${PORTVERSION}${EXTRACT_SUFX}.asc

post-build:
	@(cd ${WRKSRC}/backends && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${PORTNAME})

do-install:
	(cd ${WRKSRC}/backends \
		&& ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc/man \
		&& ${INSTALL_MAN} ${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
