# New ports collection makefile for:   emelfm2
# Date created:        01 Novemeber 2003
# Whom:                Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	emelfm2
PORTVERSION=	0.3.2
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.emelfm2.net/rel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt

MAINTAINER=	mva@sysfault.org
COMMENT=	The gtk2 port of emelfm, a fast graphical filemanager

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ENV=	CC=${CC} LDFLAGS="${LDFLAGS}" DOC_DIR="${DOCSDIR}/"
MAN1=		emelfm2.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
INSTALL_TARGET+=install_i18n
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

.if ${OSVERSION} < 600000
post-patch:
	@${REINPLACE_CMD} -e 's|blksize_t buf_size =|__int32_t buf_size =|g' \
		${WRKSRC}/src/e2_task_backend.c
.endif

.include <bsd.port.post.mk>
