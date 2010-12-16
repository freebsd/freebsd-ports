# ex:ts=8
# Ports collection makefile for:	moreutils
# Date created:	16 June 2009
# Whom:		Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	moreutils
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	corky1951@comcast.net
COMMENT=	Additional Unix utilities

RUN_DEPENDS=	${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run

USE_PERL5=	yes

PLIST_FILES=	bin/chronic \
		bin/combine \
		bin/ifne \
		bin/isutf8 \
		bin/lckdo \
		bin/mispipe \
		bin/pee \
		bin/sponge \
		bin/ts \
		bin/vidir \
		bin/vipe \
		bin/zrun

ALL_TARGET=	bins

WRKSRC=		${WRKDIR}/${PORTNAME}

.if !defined(NO_INSTALL_MANPAGES)
ALL_TARGET+=	mans extraman

CANNED_MAN=	ifne.1 \
		isutf8.1 \
		lckdo.1 \
		mispipe.1 \
		pee.1 \
		sponge.1
MAN1=		chronic.1 \
		combine.1 \
		ts.1 \
		vidir.1 \
		vipe.1 \
		zrun.1 \
		${CANNED_MAN}
MANCOMPRESSED=	no

post-patch:
	cd ${FILESDIR} && ${CP} ${CANNED_MAN} ${WRKSRC}/

post-install:
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1/
.endif

.include <bsd.port.mk>
