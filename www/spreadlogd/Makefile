PORTNAME=	spreadlogd
PORTVERSION=	1.4.2
CATEGORIES=	www net
MASTER_SITES=	http://www.lethargy.org/mod_log_spread/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Backend for mod_log_spread

LICENSE=	ART10

LIB_DEPENDS=	libgnuregex.so:devel/libgnuregex \
		libspread.so:net/spread

MAKEFILE=	makefile
USE_RC_SUBR=	spreadlogd

PLIST_FILES=	sbin/spreadlogd etc/spreadlogd.conf.sample
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/spreadlogd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spreadlogd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/spreadlogd.conf \
		${STAGEDIR}${PREFIX}/etc/spreadlogd.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
