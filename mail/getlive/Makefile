# New ports collection makefile for:	GetLive
# Date created:				20 April 2008
# Whom:					ayunyan <ayunyan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	getlive
DISTVERSION=	0_57
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/GetLive/${PORTVERSION}%20%28Beta%29
DISTNAME=	GetLive_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ayu@commun.jp
COMMENT=	Get mail from Hotmail (Live) mailboxes

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		procmail:${PORTSDIR}/mail/procmail \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/getlive etc/getlive.conf.sample
PORTDOCS=	ChangeLog License Manual

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/GetLive.pl ${PREFIX}/bin/getlive
	${INSTALL_DATA} ${FILESDIR}/getlive.conf.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
