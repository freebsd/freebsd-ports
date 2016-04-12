# Created by: Ken Wong <wongk@apt.homeunix.net>
# $FreeBSD$

PORTNAME=	pcrs
PORTVERSION=	0.0.3
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://distfiles.master.finkmirrors.net/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	wongk@apt.homeunix.net
COMMENT=	Perl-compatible regular expression based substitutions

LICENSE=	LGPL21

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/pcrsed \
		lib/libpcrs.a \
		lib/libpcrs.so \
		lib/libpcrs.so.0 \
		man/man3/pcrs.3.gz

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcrsed ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
