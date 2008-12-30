# New ports collection makefile for:	free-sa
# Date created:				22 Mar 2007
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	free-sa
PORTVERSION=	1.5.1
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	toxa@toxahost.ru
COMMENT=	Statistic analyzer for daemons log files similar to SARG

PORTDOCS=	COPYING INSTALL README README.DEV ChangeLog FAQ THANKS
DOCSDIR=	share/doc/free-sa-${DISTVERSION}

MAN1=	free-sa.1
MAN5=	free-sa.conf.5

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,PREFIX =,PREFIX ?=,' ${WRKSRC}/global.mk

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile
.endif

.include <bsd.port.post.mk>
