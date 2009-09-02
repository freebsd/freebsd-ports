# New ports collection makefile for:	fdm
# Date created:		25 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fdm
PORTVERSION=	1.6
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	chifeng@gmail.com
COMMENT=	Fetches and delivers mail

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		tdb.1:${PORTSDIR}/databases/tdb

PLIST_FILES=	bin/fdm
PORTDOCS=	CHANGES README MANUAL
PORTEXAMPLES=	n-marriott.conf f-terbeck.conf t-ulmer.conf w-maier.conf g-lando.conf
MAKE_ARGS=	-DPCRE -DDB

MAN1=	fdm.1
MAN5=	fdm.conf.5

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/*.[ch15]
	@${REINPLACE_CMD} -e 's|/usr/local/include/openssl|/usr/include/openssl|;\
		s|/usr/local|${LOCALBASE}|g' ${WRKSRC}/${MAKEFILE}

post-install:
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${EXAMPLESDIR}/
.endif
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
