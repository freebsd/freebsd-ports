# $FreeBSD$

PORTNAME=	scdoc
DISTVERSION=	1.9.3
CATEGORIES=	textproc
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/
DISTFILES=	${DISTVERSIONFULL}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple man page generator for POSIX systems written in C99

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
TEST_TARGET=	check
PLIST_FILES=	bin/${PORTNAME} \
		libdata/pkgconfig/${PORTNAME}.pc \
		man/man1/${PORTNAME}.1.gz \
		man/man5/${PORTNAME}.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		-e '/pkgconfig/s,lib,libdata,' \
		-e '/BIN/s,install -Dm755,${INSTALL_PROGRAM},' \
		-e '/MAN/s,install -Dm644,${INSTALL_MAN},' \
		-e '/PC/s,install -Dm644,${INSTALL_DATA},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/prefix/s,/usr,${PREFIX},' \
		${WRKSRC}/${PORTNAME}.pc
	@${REINPLACE_CMD} -i '' 's,--date=,-f "%F %T %z" ,' \
		${WRKSRC}/test/preamble

.include <bsd.port.mk>
