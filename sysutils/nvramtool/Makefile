PORTNAME=	nvramtool
PORTVERSION=	r6440
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.zonov.org/${PORTNAME}/

MAINTAINER=	zont@FreeBSD.org
COMMENT=	Utility for reading, writing the contents of CMOS memory
WWW=		https://www.coreboot.org/Nvramtool

USES=		gmake tar:bzip2

ONLY_FOR_ARCHS=	amd64 i386

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cli/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
