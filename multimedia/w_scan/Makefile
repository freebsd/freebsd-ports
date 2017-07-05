# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	w_scan
PORTVERSION=	20170107
CATEGORIES=	multimedia
MASTER_SITES=	http://wirbel.htpc-forum.de/w_scan/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Perform frequency scans for DVB and ATSC transmissions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat

GNU_CONFIGURE=	yes
USES=		dos2unix gettext iconv localbase tar:bzip2
DOS2UNIX_GLOB=	*.c *.h
LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	COPYING ChangeLog README
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -f ${FILESDIR}/types.sed ${WRKSRC}/configure ${WRKSRC}/*.c ${WRKSRC}/*.h

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
