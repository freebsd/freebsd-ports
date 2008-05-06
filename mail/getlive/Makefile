# New ports collection makefile for: getlive
# Date created:	20 April 2008
# Whom:		ayunyan
#
# $FreeBSD$
#

PORTNAME=	getlive
PORTVERSION=	0.56
CATEGORIES=	mail
MASTER_SITES=	SF
DISTNAME=	GetLive_0_56
EXTRACT_SUFX=	.tgz

MAINTAINER=	ayunyan@gmail.com
COMMENT=	Get mail from hotmail (live) mailboxes

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes
USE_PERL5_RUN=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/GetLive.pl ${PREFIX}/bin/getlive
	${INSTALL_DATA} ${FILESDIR}/getlive.conf.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ChangeLog License Manual
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
