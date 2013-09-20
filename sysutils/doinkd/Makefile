# Created by: Andrew <andrew@ugh.net.au>, Iain Templeton <iain@ugh.net.au>
# $FreeBSD$

PORTNAME=	doinkd
PORTVERSION=	0.01
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF/idled/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A daemon that logs out idle users and those users hogging resources

MANCOMPRESSED=	yes
MAN5=		doinkd.cf.5
MAN8=		doinkd.8

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	etc/doinkd/doinkd.cf.template sbin/doinkd
PLIST_DIRSTRY=	etc/doinkd

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	(cd ${WRKSRC}; make clean)

pre-install:
	${MKDIR} ${PREFIX}/etc/doinkd

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/doinkd

.include <bsd.port.post.mk>
