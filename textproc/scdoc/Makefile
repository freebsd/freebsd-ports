# $FreeBSD$

PORTNAME=	scdoc
DISTVERSION=	1.6.0
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
PLIST_FILES=	bin/scdoc \
		man/man1/scdoc.1.gz \
		man/man5/scdoc.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		-e '/BIN/s,install -Dm755,${INSTALL_PROGRAM},' \
		-e '/MAN/s,install -Dm644,${INSTALL_MAN},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -i '' 's,--date=,-f "%F %T %z" ,' \
		${WRKSRC}/test/preamble

.include <bsd.port.mk>
