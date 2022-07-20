PORTNAME=	mtx
PORTVERSION=	1.3.12
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Control SCSI media changer devices

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes
PLIST_FILES=	sbin/mtx sbin/tapeinfo sbin/loaderinfo sbin/scsitape sbin/scsieject \
		man/man1/loaderinfo.1.gz man/man1/mtx.1.gz man/man1/tapeinfo.1.gz \
		man/man1/scsitape.1.gz man/man1/scsieject.1.gz

post-patch:
	${REINPLACE_CMD} -e 's|@prefix@|${STAGEDIR}${PREFIX}|g' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|@mandir@|${STAGEDIR}${PREFIX}/man|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
