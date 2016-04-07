# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	foo2zjs
PORTVERSION=	20150511
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/bsam/${PORTNAME}  \
		ftp://ftp.wart.ru/pub/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Driver for printers that use the ZjStream wire protocol

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcups.so:print/cups
RUN_DEPENDS=	${LOCALBASE}/share/foomatic/db/oldprinterids:print/foomatic-db \
		foomatic-rip:print/cups-filters \
		gsed:textproc/gsed

PROJECTHOST=	bsdistfiles
USES=		ghostscript gmake shebangfix
SHEBANG_FILES=	msexpand printer-profile.sh
SUB_FILES=	pkg-message ${DEVDCONF_FILE}
EXTRAFILES=	msexpand getweb
DEVDCONF_FILE=	${PORTNAME}.conf

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|g' -e 's|^PREFIX|PREFIX?|g' ${WRKSRC}/icc2ps/Makefile

post-install:
	cd ${WRKSRC} && \
		${INSTALL_SCRIPT} ${EXTRAFILES} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}/etc/devd
	cd ${WRKDIR} && \
		${INSTALL_SCRIPT} ${DEVDCONF_FILE} ${STAGEDIR}${PREFIX}/etc/devd
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/foo2zjs-icc2ps

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ChangeLog INSTALL README manual.pdf
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
