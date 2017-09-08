# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rats
PORTVERSION=	2.4
CATEGORIES=	security devel
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/rough-auditing-tool-for-security/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code auditing tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
USES=		gmake tar:tgz
CONFIGURE_ARGS=	--with-expat-lib=${LOCALBASE}/lib \
		--with-expat-include=${LOCALBASE}/include/xml \
		--datadir=${DATADIR}

ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E '/^CFLAGS/! s,(BIN|LIB|MAN|SHARE)DIR),DESTDIR)$$(&,g' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
