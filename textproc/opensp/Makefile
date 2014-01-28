# Created by: kuriyama
# $FreeBSD$

PORTNAME=	OpenSP
PORTVERSION=	1.5.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/openjade/${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	This package is a collection of SGML/XML tools called OpenSP

OPTIONS_DEFINE=	DOCS NLS

USE_LDCONFIG=	yes
USES=		gmake iconv perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${PREFIX}/share/sgml/openjade \
		--disable-doc-build
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext


PORTDOCS=	*.htm NEWS AUTHORS README ABOUT-NLS BUGS ChangeLog

# This port cannot be CFLAGS safe, using optimizations such as
# 'march=-mpentium -Os' produces core dumps with certain input files
# Therefore, we'd better remove all machine optimizations and any -O
# other than -O{0,1,}. Idea taken from palm/prc-tools-gcc.
CPPFLAGS:=	-O ${CFLAGS:N-O*:N-m*}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS:N\*.htm} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
