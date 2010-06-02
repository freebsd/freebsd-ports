# New ports collection makefile for:	httrack
# Date created:		Sun Jun 17 10:28:52 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httrack
PORTVERSION=	3.43.9
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://sunpoet.net/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9]*)$/-\1/}C

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Easy-to-use offline browser utility and website copier

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		htsserver.1 httrack.1 proxytrack.1 webhttrack.1

.if !defined(NOPORTDATA)
USE_LDCONFIG+=	${PREFIX}/lib/httrack
.endif

post-patch:
	@${REINPLACE_CMD} -e '/DEFAULT_CFLAGS=/ s|-O -g3 ||g' \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/ install-data-hook/D' ${WRKSRC}/html/Makefile.in
.if defined(NOPORTDATA)
	@${REINPLACE_CMD} -E '/^SUBDIRS = / s/ (lang|libtest|templates)//g' ${WRKSRC}/Makefile.in
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| html||' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/html/httrack.css ${DOCSDIR}/html/httrack.css
.endif

.include <bsd.port.mk>
