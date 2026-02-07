PORTNAME=	fdm
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Fetches and delivers mail
WWW=		https://github.com/nicm/fdm

LICENSE=	ISCL

LIB_DEPENDS=	libtdb.so:databases/tdb

USES=		autoreconf ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nicm

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

PLIST_FILES=	bin/fdm share/man/man1/fdm.1.gz share/man/man5/fdm.conf.5.gz
PORTDOCS=	CHANGES README MANUAL
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES PCRE
OPTIONS_DEFAULT=PCRE

PCRE_LIBS=	-lpcre2-8
PCRE_LIB_DEPENDS=libpcre2-8.so:devel/pcre2
PCRE_CONFIGURE_ENABLE=	pcre2

post-patch:
	${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/*.[15] ${WRKSRC}/MANUAL
	${ECHO_CMD} 'lex.c: parse.h' >> ${WRKSRC}/Makefile.am

pre-configure:
	cd ${WRKSRC} && autoupdate

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
