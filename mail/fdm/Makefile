# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdm
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	chifeng@gmail.com
COMMENT=	Fetches and delivers mail

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre \
		tdb.1:${PORTSDIR}/databases/tdb

PLIST_FILES=	bin/fdm
PORTDOCS=	CHANGES README MANUAL
PORTEXAMPLES=	n-marriott.conf f-terbeck.conf t-ulmer.conf w-maier.conf g-lando.conf
MAKE_ARGS=	-DPCRE -DDB

MAN1=	fdm.1
MAN5=	fdm.conf.5

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/*.[ch15]
	@${REINPLACE_CMD} -e 's|/usr/local/include/openssl|/usr/include/openssl|;\
		s|-I-||g;\
		s|/usr/local|${LOCALBASE}|g' ${WRKSRC}/${MAKEFILE}

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${EXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
