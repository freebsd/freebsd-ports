# New ports collection makefile for:	fdm
# Date created:		25 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fdm
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	SFE

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Fetches and delivers mail

PLIST_FILES=	bin/fdm etc/fdm.conf.sample %%EXAMPLESDIR%%/n-marriott.conf \
		%%EXAMPLESDIR%%/w-maier.conf
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	CHANGES README MANUAL

CFLAGS=	-I/usr/include/openssl

MAN1=	fdm.1
MAN5=	fdm.conf.5

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/*.[ch15]

post-install:
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/examples/n-marriott.conf ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/examples/w-maier.conf ${EXAMPLESDIR}
	@${LN} -sf ${EXAMPLESDIR}/n-marriott.conf ${PREFIX}/etc/fdm.conf.sample
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
