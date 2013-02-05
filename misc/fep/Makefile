# Created by: Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
# $FreeBSD$

PORTNAME=	fep
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/fep/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose front end for command line editing

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05

MAN1=		fep.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/fep

NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800039
BROKEN=		Does not compile without sgtty
.endif

.include <bsd.port.post.mk>
