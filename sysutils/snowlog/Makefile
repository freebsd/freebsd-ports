# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	snowlog
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://kiza.kcore.de/software/snowlog/download/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A webserver access log browser/analyzer

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre

MAN1=		snowlog.1
DOCS=		INSTALLATION doc/README doc/filters.example
SHAREDOCS=	referers.regexp useragents.regexp

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/share && ${INSTALL_DATA} ${SHAREDOCS} ${DATADIR}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
