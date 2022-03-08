# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	edid-decode
PORTVERSION=	0.1.20220301
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Decodes binary EDID information from monitors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake tar:xz

LDFLAGS+=	-lm

PLIST_FILES=	bin/edid-decode \
		share/man/man1/edid-decode.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/share/man/man1

dist: clean
	@${MKDIR} ${WRKSRC}
	@git clone https://git.linuxtv.org/edid-decode.git ${WRKSRC}
	@${RM} -rf ${WRKSRC}/.git*
	@${TAR} -C ${WRKDIR} -cvJpf ${DISTDIR}/${DISTFILES} ${DISTNAME}

.include <bsd.port.mk>
