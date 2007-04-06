# New ports collection makefile for:	fdm
# Date created:		25 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fdm
PORTVERSION=	1.1
CATEGORIES=	mail
MASTER_SITES=	SFE

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Fetches and delivers mail

PLIST_FILES=	bin/fdm etc/fdm.conf.sample ${CFGEXAMPLES:S|^|%%EXAMPLESDIR%%/|:S|$|.conf|}
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	CHANGES README MANUAL
CFGEXAMPLES=	n-marriott f-terbeck t-ulmer w-maier

CFLAGS=	-I/usr/include/openssl

MAN1=	fdm.1
MAN5=	fdm.conf.5

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/*.[ch15]

post-install:
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${CFGEXAMPLES:S|^|${WRKSRC}/examples/|:S|$|.conf|} ${EXAMPLESDIR}/
	@${LN} -sf ${EXAMPLESDIR}/n-marriott.conf ${PREFIX}/etc/fdm.conf.sample
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
