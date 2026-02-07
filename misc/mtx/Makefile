PORTNAME=	mtx
PORTVERSION=	1.3.12
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Control SCSI media changer devices
WWW=		https://sourceforge.net/projects/mtx/

LICENSE=	GPLv2

USES=		gmake

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	sbin/mtx sbin/tapeinfo sbin/loaderinfo sbin/scsitape sbin/scsieject \
		share/man/man1/loaderinfo.1.gz share/man/man1/mtx.1.gz share/man/man1/tapeinfo.1.gz \
		share/man/man1/scsitape.1.gz share/man/man1/scsieject.1.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-FreeBSD_14
.endif

post-patch:
	${REINPLACE_CMD} -e 's|@prefix@|${STAGEDIR}${PREFIX}|g' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|@mandir@|${STAGEDIR}${PREFIX}/share/man|g' \
		${WRKSRC}/Makefile.in
#	${REINPLACE_CMD} -e '/false, true/d' \
#		${WRKSRC}/mtx.h

.include <bsd.port.mk>
