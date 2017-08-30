# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdm
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Fetches and delivers mail

LICENSE=	ISCL

LIB_DEPENDS=	libtdb.so:databases/tdb

USE_GITHUB=	yes
GH_ACCOUNT=	nicm
USES=		autoreconf:build ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

PLIST_FILES=	bin/fdm man/man1/fdm.1.gz man/man5/fdm.conf.5.gz
PORTDOCS=	CHANGES README MANUAL
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES PCRE
OPTIONS_DEFAULT=PCRE

PCRE_CFLAGS=	-DPCRE
PCRE_LIBS=	-lpcre
PCRE_LIB_DEPENDS=libpcre.so:devel/pcre

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/*.[15] ${WRKSRC}/MANUAL
	@${ECHO_CMD} 'lex.c: parse.h' >> ${WRKSRC}/Makefile.am

pre-configure:
	@cd ${WRKSRC} && sh autogen.sh

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
