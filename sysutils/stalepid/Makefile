# New ports collection makefile for:	stalepid
# Date created:		4 December 2003
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	stalepid
PORTVERSION=	1.0.b1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/stalepid/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Check for stale pid files and remove them

.include <bsd.port.pre.mk>
RUN_DEPENDS=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/Errno.pm:${PORTSDIR}/devel/p5-Errno
.endif

USE_PERL5_RUN=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

MAN1=		stalepid.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/stalepid

.include <bsd.port.post.mk>
