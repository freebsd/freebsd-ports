# ex:ts=8
# New ports collection makefile for:	fcron
# Date created:			Mar 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fcron
PORTVERSION=	1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://fcron.free.fr/
MASTER_SITE_SUBDIR=	system/daemons/cron
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ijliao@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}" \
		--with-rootname=root --with-rootgroup=wheel \
		--with-answer-all=yes

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/fcron
PLIST_SUB=	PORTVERSION=${PORTVERSION}
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		fcrontab.1
MAN3=		bitstring.3
MAN5=		fcrontab.5
MAN8=		fcron.8

.include <bsd.port.mk>
