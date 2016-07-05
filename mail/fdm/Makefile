# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdm
PORTVERSION=	1.8
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fetches and delivers mail

LICENSE=	ISCL

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libtdb.so:databases/tdb

USES=		ssl
HAS_CONFIGURE=	yes
MAKE_ARGS=	-DPCRE -DDB INSTALLBIN="${INSTALL_PROGRAM}"

PLIST_FILES=	bin/fdm man/man1/fdm.1.gz man/man5/fdm.conf.5.gz
PORTDOCS=	CHANGES README MANUAL
PORTEXAMPLES=	n-marriott.conf f-terbeck.conf t-ulmer.conf w-maier.conf g-lando.conf

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/*.[ch15]
	@${REINPLACE_CMD} -e 's|/usr/local/include/openssl|${OPENSSLINC}|;\
		s|-I-||g; s|-g bin -o root||g; s|^FDEBUG|#&|;\
		s|/usr/local|${LOCALBASE}|g' ${WRKSRC}/${MAKEFILE}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
