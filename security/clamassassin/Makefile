# New ports collection makefile for:	clamassassin
# Date created:				16 October 2004
# Whom:					Matt <matt@xtaz.net>
#
# $FreeBSD$
#

PORTNAME=	clamassassin
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://drivel.com/clamassassin/

MAINTAINER=	ports@freebsd.org
COMMENT=	A simple virus filter wrapper for ClamAV

BUILD_DEPENDS=	sigtool:${PORTSDIR}/security/clamav \
		formail:${PORTSDIR}/mail/procmail
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_FILES=	bin/clamassassin

GNU_CONFIGURE=	yes

OPTIONS=	CLAMDSCAN "Scanning using clamd" on \
		SUBREWRITE "Mail subject rewriting" off

.include <bsd.port.pre.mk>

.if !defined (WITHOUT_CLAMDSCAN)
CONFIGURE_ARGS+=	--enable-clamdscan
.endif

.if defined (WITH_SUBREWRITE)
CONFIGURE_ARGS+=	--enable-subject-rewrite
.endif

.include <bsd.port.post.mk>
