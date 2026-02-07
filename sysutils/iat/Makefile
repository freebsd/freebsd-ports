PORTNAME=	iat
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	BERLIOS

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Converter of many types of CD-ROM image file formats into ISO-9660
WWW=		http://iat.berlios.de/

LICENSE=	GPLv2 GPLv3 # code says GPLv2, COPYING says GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING

USES=		tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/iat share/man/man1/iat.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/install-data-am:/ s|install-includeHEADERS||' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
