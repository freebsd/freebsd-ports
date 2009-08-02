# New ports collection makefile for:	httrack
# Date created:		Sun Jun 17 10:28:52 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httrack
PORTVERSION=	3.43.2
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://sunpoet.net/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9]*)$/-\1/}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Easy-to-use offline browser utility and website copier

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

MAN1=		htsserver.1 httrack.1 proxytrack.1 webhttrack.1

.if defined(NOPORTDATA) || defined(NOPORTDOCS)
NOPORTDATA=	yes
NOPORTDOCS=	yes
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O -g3 ||g' \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
