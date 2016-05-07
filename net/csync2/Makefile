# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csync2
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://oss.linbit.com/csync2/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Cluster synchronization tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librsync.so.2:net/librsync1 \
		libgnutls.so:security/gnutls \
		libsqlite3.so:databases/sqlite3

OPTIONS_DEFINE=	CSYNC2_COMPARE DOCS
OPTIONS_SUB=	yes
CSYNC2_COMPARE_DESC=		Install csync2-compare script
CSYNC2_COMPARE_RUN_DEPENDS=	bash:shells/bash

USES=		pkgconfig shebangfix
SHEBANG_FILES=	csync2-compare

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_PDFLATEX=
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USE_RC_SUBR=	csync2

SUB_FILES=	pkg-install

post-patch:
	@${REINPLACE_CMD} -e 's|(localstatedir)/lib|(localstatedir)/db|' \
		-e 's/-ldl//' ${WRKSRC}/Makefile.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/csync2.cfg \
		${STAGEDIR}${PREFIX}/etc/csync2.cfg.sample
	${MKDIR} ${STAGEDIR}/var/backups/csync2

.include <bsd.port.mk>
