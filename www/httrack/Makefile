# New ports collection makefile for:	httrack
# Date created:		Sun Jun 17 10:28:52 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httrack
DISTVERSION=	3.43
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Easy-to-use offline browser utility and website copier

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
DISTREVISION=	1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.${DISTREVISION}

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
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
