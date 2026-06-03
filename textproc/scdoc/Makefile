PORTNAME=	scdoc
DISTVERSION=	1.11.4
CATEGORIES=	textproc
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Small man page generator
WWW=		https://git.sr.ht/~sircmpwn/scdoc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
MAKE_ENV=	PCDIR='$$(PREFIX)/libdata/pkgconfig'
TEST_TARGET=	check
PLIST_FILES=	bin/${PORTNAME} \
		libdata/pkgconfig/${PORTNAME}.pc \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}.5.gz

post-patch:
	@${REINPLACE_CMD} '/-static/d' ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
