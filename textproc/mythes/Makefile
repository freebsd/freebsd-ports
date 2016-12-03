# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/hunspell/MyThes/${PORTVERSION}/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Simple thesaurus library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.5.so:textproc/hunspell

USES=		libtool pathfix perl5 pkgconfig shebangfix
USE_LDCONFIG=	yes
USE_PERL5=	run
SHEBANG_FILES=	th_gen_idx.pl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
