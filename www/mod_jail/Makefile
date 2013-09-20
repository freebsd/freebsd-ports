# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	mod_jail
PORTVERSION=	0.5.2
CATEGORIES=	www
MASTER_SITES=	http://mod-jail.googlecode.com/files/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to enable an easy alternative to mod_chroot


USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

NOPORTDOCS=	yes
PORTDOCS=	changelog.html documentation.html download.html \
		index.html

NO_STAGE=	yes
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
