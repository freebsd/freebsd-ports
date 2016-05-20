# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	amberfish
PORTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	SF/${PORTNAME}/Amberfish%20source%20-%20stable/${PORTVERSION}	\
		http://etymon.com/software/amberfish/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose text retrieval Software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3

USES=		gmake makeinfo
GNU_CONFIGURE=	yes
ALL_TARGET=	all html

PLIST_FILES=	bin/af man/man1/af.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${FILESDIR}/porter.cc ${WRKSRC}/src

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${MAKEFLAGS} ||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|cp |$${BSD_INSTALL_MAN} |' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O3 |@CFLAGS@ | ; \
		s|make strip|| ; \
		s|cp |$${BSD_INSTALL_PROGRAM} |' ${WRKSRC}/src/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/amberfish.png ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
