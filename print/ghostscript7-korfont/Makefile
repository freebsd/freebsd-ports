PORTNAME=	ghostscript
PORTVERSION=	7.07
PORTREVISION=	9
CATEGORIES=	print korean
PKGNAMESUFFIX=	7-korfont

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Korean font support for Ghostscript 7.x

DEPRECATED=	Obsolete and unsupported upstream
EXPIRATION_DATE=2023-06-30

FORBIDDEN=	CVE-2023-28879

RUN_DEPENDS=	${LOCALBASE}/share/fonts/CIDFont/Munhwa-Regular:korean/munhwafonts-cid \
		${LOCALBASE}/share/ghostscript/Resource/CIDFont/HYSMyeongJo-Medium:print/ghostscript7-commfont

USES=		ghostscript:7,run metaport

.include <bsd.port.mk>
