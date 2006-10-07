# New ports collection makefile for:	dwdiff
# Date created:		30 September 2006
# Whom:			Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	dwdiff
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	http://os.ghalkes.nl/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@logvinov.com
COMMENT=	A delimited word diff program

HAS_CONFIGURE=	yes

OPTIONS=	GETTEXT   "Build with gettext support"	on

MAN1=		dwdiff.1
PORTDOCS=	COPYING Changelog README
PLIST_FILES=	bin/dwdiff

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GETTEXT)
USE_GETTEXT=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--without-gettext
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in COPYING Changelog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
