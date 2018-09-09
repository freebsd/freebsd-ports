# Created by: ijliao
# $FreeBSD$

PORTNAME=	ccrypt
DISTVERSION=	1.11
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION}/ \
		http://www.mathstat.dal.ca/~selinger/ccrypt/download/${DISTVERSION}/

MAINTAINER=	dev2@heesakkers.info
COMMENT=	Command-line utility for encrypting and decrypting files and streams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README doc/ccrypt.html doc/cypfaq01.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
