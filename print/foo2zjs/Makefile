# New ports collection makefile for:	foo2zjs
# Date created:		2006-03-17
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	foo2zjs
PORTVERSION=	20060504
CATEGORIES=	print
MASTER_SITES=	http://foo2zjs.rkkda.com/
DISTNAME=	${PORTNAME}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Driver for printers that use the ZjStream wire protocol

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${LOCALBASE}/share/foomatic/db/oldprinterids:${PORTSDIR}/print/foomatic-db \
		foomatic-rip:${PORTSDIR}/print/foomatic-filters

USE_GHOSTSCRIPT=	yes
USE_GMAKE=	yes
SUB_FILES=	pkg-message

MAN1=	foo2hp.1 foo2oak-wrapper.1 foo2zjs-wrapper.1 oakdecode.1 foo2hp2600-wrapper.1 foo2oak.1 foo2zjs.1 zjsdecode.1

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|g' -e 's|^PREFIX|PREFIX?|g' ${WRKSRC}/icc2ps/Makefile

post-install:
	@cd ${WRKSRC} && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ChangeLog README manual.pdf
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
