# $FreeBSD$

PORTNAME=	enchive
PORTVERSION=	3.2
CATEGORIES=	security
MASTER_SITES=	https://github.com/skeeto/enchive/archive/
DISTFILES=	${PORTVERSION}.tar.gz

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Tool to encrypt files to yourself for long-term archival

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/UNLICENSE

USES=		gmake
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/UNLICENSE

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|CC?|g' -e 's|^CFLAGS|CFLAGS?|g' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/UNLICENSE ${STAGEDIR}/${DATADIR}/UNLICENSE

.include <bsd.port.mk>
