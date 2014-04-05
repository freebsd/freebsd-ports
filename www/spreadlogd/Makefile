# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	spreadlogd
PORTVERSION=	1.4.2
CATEGORIES=	www net
MASTER_SITES=	http://www.lethargy.org/mod_log_spread/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	The backend of mod_log_spread

DEPRECATED=	Depends on expired net/spread
EXPIRATION_DATE=2014-05-01

LICENSE=	ART10

LIB_DEPENDS=	libspread.so:${PORTSDIR}/net/spread

MAKEFILE=	makefile

USE_RC_SUBR=	spreadlogd

PLIST_FILES=	sbin/spreadlogd etc/spreadlogd.conf.sample

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/spreadlogd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spreadlogd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL} ${WRKSRC}/spreadlogd.conf ${STAGEDIR}${PREFIX}/etc/spreadlogd.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
