# ex:ts=8
# Ports collection makefile for:  bk2site
# Date created:                   Wed Dec 06, 2000
# Whom:                           clive
#
# $FreeBSD$
#

PORTNAME=	bk2site
PORTVERSION=	1.1.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clive@FreeBSD.org

MAN1=		bk2site.1
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --enable-standard-datadir

post-patch:
	${PERL} -pi -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/dot.bk2siterc

post-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${CP} ${WRKSRC}/*.html ${PREFIX}/etc/${PORTNAME}
	${CP} ${WRKSRC}/*.gif ${PREFIX}/share/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
