# $FreeBSD$

PORTNAME=	edbrowse
PORTVERSION=	3.4.10
CATEGORIES=	www editors
MASTER_SITES=	http://the-brannons.com/edbrowse/ \
		http://rithmomachia.org/edbrowse/

MAINTAINER=	david.vionnet@vmailbox.org
COMMENT=	Line-oriented Web browser and text editor

LICENSE=	GPLv2

BUILD_DEPENDS=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libmozjs185.so:${PORTSDIR}/lang/spidermonkey185 \
		libcurl.so:${PORTSDIR}/ftp/curl

USE_OPENSSL=	yes
USES=		readline zip

OPTIONS_DEFINE=	DOCS

WRKBASE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKBASE}/src

MAKEFILE=	makefile.bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/edbrowse ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKBASE}/doc/man-edbrowse-debian.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/edbrowse.1

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKBASE}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKBASE}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKBASE}/README ${STAGEDIR}${DOCSDIR}
	(cd ${WRKBASE}/doc && \
		${FIND} . \( -name setup.ebrc -or -name "man-edbrowse*" \) -delete  && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
