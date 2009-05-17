# New ports collection makefile for:		mod_jail
# Date created:				Oct 7 2005
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	mod_jail
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://igorpopov.newmail.ru/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 1.3.x/2.0.xx module to enable an easy alternative to mod_chroot

MAKE_JOBS_SAFE=  yes

WRKSRC=		${WRKDIR}/mod_jail
USE_APACHE=	1.3+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

PORTDOCS=	changelog.html documentation.html download.html \
		index.html

.include <bsd.port.pre.mk>

post-extract:
	@${REINPLACE_CMD} -e "s|= apxs|= ${APXS}|" ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
