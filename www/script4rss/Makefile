# Created by: ijliao
# $FreeBSD$

PORTNAME=	script4rss
PORTVERSION=	0.4b
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easily create scripts to convert HTML pages to RSS feeds

USES=		perl5
USE_BZIP2=	yes
USE_PERL5=	run
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,#!/usr/bin/perl,#!${SETENV} perl," ${WRKSRC}/script4rss.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/script4rss.pl ${PREFIX}/bin/script4rss
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
