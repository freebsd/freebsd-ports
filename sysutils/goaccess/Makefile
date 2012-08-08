# New ports collection makefile for:	goaccess
# Date created:		2010-11-17
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	goaccess
PORTVERSION=	0.5
CATEGORIES=	sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Real-time Apache web log analyzer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	glib-2.0:${PORTSDIR}/devel/glib20 \
		GeoIP:${PORTSDIR}/net/GeoIP

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
.endif

PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/,} ${PREFIX}/man/man1
.endif
	${INSTALL_SCRIPT} ${PORTNAME:S,^,${WRKSRC}/,} ${PREFIX}/bin

.include <bsd.port.mk>
