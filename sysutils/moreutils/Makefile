# ex:ts=8
# Ports collection makefile for:	moreutils
# Date created:	16 June 2009
# Whom:		Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	moreutils
PORTVERSION=	0.40
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	corky1951@comcast.net
COMMENT=	Additional Unix utilities

USE_PERL5=	yes

PLIST_FILES=	bin/combine \
		bin/ifne \
		bin/isutf8 \
		bin/lckdo \
		bin/mispipe \
		bin/parallel \
		bin/pee \
		bin/sponge \
		bin/ts \
		bin/vidir \
		bin/vipe \
		bin/zrun

ALL_TARGET=	bins

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		combine.1 \
		ifne.1 \
		isutf8.1 \
		lckdo.1 \
		mispipe.1 \
		parallel.1 \
		pee.1 \
		sponge.1 \
		ts.1 \
		vidir.1 \
		vipe.1 \
		zrun.1

ALL_TARGET+=	mans extraman
MANCOMPRESSED=	no

CANNED_MAN=	ifne.1 \
		isutf8.1 \
		lckdo.1 \
		mispipe.1 \
		parallel.1 \
		pee.1 \
		sponge.1

post-patch:
.for f in ${CANNED_MAN}
	${CP} ${FILESDIR}/${f} ${WRKSRC}
.endfor

post-install:
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${manpage} ${MANPREFIX}/man/man1
.endfor

.endif

.include <bsd.port.post.mk>
