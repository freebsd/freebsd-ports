# New ports collection makefile for:	comclear
# Date created:		26 November 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	comclear
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	http://www.neuro-tech.net/files/

MAINTAINER=	roam@FreeBSD.org

.if		defined(WITH_GTK)
BUILD_DEPENDS=	${X11BASE}/bin/gtk12-config:${PORTSDIR}/x11-toolkits/gtk12/
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
.endif

USE_GMAKE=	yes
USE_AUTOMAKE=	yes

# Do not install docs by default, see the ifdef'd post-install below.
post-configure:
		${PERL} -pi.fbsd -e 's/^install-data-am:.*/install-data-am:/' ${WRKSRC}/Makefile

.if		!defined(NOPORTDOCS)
post-install:
		cd ${WRKSRC} && ${GMAKE} install-docDATA
.endif

.include <bsd.port.mk>
