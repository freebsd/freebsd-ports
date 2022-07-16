# Created by: Mageirias Anastasios <anastmag@gmail.com>

PORTNAME=	clamfs
PORTVERSION=	1.2.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/burghardt/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	anastasios@mageirias.com
COMMENT=	User-space fs with on-access antivirus scanning

LICENSE=	GPLv2

BUILD_DEPENDS=	boost-libs>=1.33:devel/boost-libs
LIB_DEPENDS=	libPocoFoundation.so:devel/poco \
		libPocoNet.so:devel/poco \
		libPocoXML.so:devel/poco \
		librlog.so:devel/rlog
RUN_DEPENDS=	clamd:security/clamav

USES=		autoreconf compiler:c++11-lib fuse:3 pkgconfig

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/clamfs \
		man/man1/clamfs.1.gz

PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror ||g' ${WRKSRC}/configure.ac

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/socket=/s/ctl/sock/' \
		${WRKSRC}/doc/clamfs.xml ${WRKSRC}/doc/debug.xml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/clamfs.xml ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/debug.xml ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
