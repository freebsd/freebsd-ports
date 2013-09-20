# Created by: jeh@FreeBSD.org
# $FreeBSD$

PORTNAME=	mgstat
PORTVERSION=	0.12
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce graphs from mod_gzip log files

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

GNU_CONFIGURE=	yes

PORTDOCS=	Copyright README USAGE
PLIST_FILES=	bin/mgstat

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
