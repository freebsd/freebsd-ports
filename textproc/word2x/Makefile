PORTNAME=	word2x
PORTVERSION=	0.005
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-zero/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converter from MS Word to text, HTML, or LaTeX
WWW=		https://word2x.sourceforge.net/

DEPRECATED=	Obsolete converter than only supports ancient versions of Word documents
EXPIRATION_DATE=2025-04-30

USES=		gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/rtest2 bin/word2x share/man/man1/word2x.1.gz

.include <bsd.port.mk>
