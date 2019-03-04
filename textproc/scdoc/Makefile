# $FreeBSD$

PORTNAME=	scdoc
DISTVERSION=	1.9.4
CATEGORIES=	textproc
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/
DISTFILES=	${DISTVERSIONFULL}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple man page generator for POSIX systems written in C99

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
MAKE_ENV=	MANDIR='$$(_INSTDIR)/man' \
		PCDIR='$$(_INSTDIR)/libdata/pkgconfig'
TEST_TARGET=	check
PLIST_FILES=	bin/${PORTNAME} \
		libdata/pkgconfig/${PORTNAME}.pc \
		man/man1/${PORTNAME}.1.gz \
		man/man5/${PORTNAME}.5.gz

post-patch:
	@${REINPLACE_CMD} -i '' -e 's,--date=,-f "%F %T" ,' \
		-e '/SOURCE_DATE/s/date/TZ=UTC+5 &/' \
		${WRKSRC}/test/preamble

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
