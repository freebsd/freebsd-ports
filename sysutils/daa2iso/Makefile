# New ports collection makefile for:	sysutils/daa2iso
# Date created:				27 Jan 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	daa2iso
PORTVERSION=	0.1.7b
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xs4all.nl/distfiles/ \
		http://www.rwxrwxrwx.net/distfiles/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Convert PowerISO DAA files to ISO9660

PLIST_FILES=	bin/daa2iso
PORTDOCS=	daa2iso.txt

post-patch:
	@${REINPLACE_CMD} 's|exit(1)|exit(0)|' ${WRKSRC}/daa2iso.c
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/daa2iso.txt ${DOCSDIR}
.endif

# Original files from author contain no version number and are not in
# a separate directory.
.if defined(MAINTAINER)
distfile:
	rm -fr /tmp/${PORTNAME}-${PORTVERSION}
	mkdir /tmp/${PORTNAME}-${PORTVERSION}
	cd /tmp/${PORTNAME}-${PORTVERSION} && \
	fetch http://aluigi.altervista.org/mytoolz/${PORTNAME}.zip && \
	tar xf ${PORTNAME}.zip && \
	mv src/* . && \
	rm -rf ${PORTNAME}.zip *.exe src && \
	chmod 664 *
	cd /tmp && \
	tar cf ${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-${PORTVERSION}
	rm -fr /tmp/${PORTNAME}-${PORTVERSION}
.endif

.include <bsd.port.mk>
