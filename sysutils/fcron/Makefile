# ex:ts=8
# New ports collection makefile for:	fcron
# Date created:			Mar 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fcron
PORTVERSION=	1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://fcron.free.fr/
MASTER_SITE_SUBDIR=	system/daemons/cron
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}" \
		--with-rootname=root --with-rootgroup=wheel \
		--with-answer-all=yes

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/fcron
PLIST_SUB=	PORTVERSION=${PORTVERSION}
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	fcrontab.1
MAN3=	bitstring.3
MAN5=	fcrontab.5 fcron.conf.5
MAN8=	fcron.8

post-install:
	@${CP} ${WRKSRC}/files/fcron.allow ${PREFIX}/etc/fcron.allow.dist
	@${CP} ${WRKSRC}/files/fcron.deny ${PREFIX}/etc/fcron.deny.dist

.include <bsd.port.mk>
