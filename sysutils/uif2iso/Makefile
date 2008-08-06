# New ports collection makefile for:	sysutils/uif2iso
# Date created:				27 Jan 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	uif2iso
PORTVERSION=	0.1.5a
CATEGORIES=	sysutils
MASTER_SITES=	http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/distfiles/ \
		http://www.rwxrwxrwx.net/distfiles/

MAINTAINER=	carpetsmoker@rwxrwxrwx.net
COMMENT=	Convert MagicISO UIF files to ISO9660

PLIST_FILES=	bin/uif2iso
PORTDOCS=	uif2iso.txt

post-patch:
	@${REINPLACE_CMD} 's|exit(1)|exit(0)|' ${WRKSRC}/uif2iso.c

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} -lz -lssl ${WRKSRC}/uif2iso.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uif2iso ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/uif2iso.txt ${DOCSDIR}
.endif

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
