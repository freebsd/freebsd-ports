# New ports collection makefile for:	trn
# Date created:		21 October 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	trn
PORTVERSION=	3.6
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/readers/trn/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Threaded Read News newsreader

RUN_DEPENDS=	munpack:${PORTSDIR}/converters/mpack

WRKSRC=		${WRKDIR}/trn-3.6
MAN1=		trn.1 Pnews.1 Rnmail.1 newsetup.1 newsgroups.1

HAS_CONFIGURE=	Yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=	PREFIX="${PREFIX}"
CONFIGURE_ARGS=	-S

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "############################################################################"
	@${ECHO_MSG} "# Please edit lines 48 through 69 in ${PREFIX}/bin/Pnews                   #"
	@${ECHO_MSG} "# to customize news posting for your site.                                 #"
	@${ECHO_MSG} "# Remember to set the NNTPSERVER environment variable to your news server. #"
	@${ECHO_MSG} "############################################################################"
.endif

.include <bsd.port.mk>
