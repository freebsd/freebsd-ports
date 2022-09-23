PORTNAME=	schilytools
DISTVERSION=	2
CATEGORIES=	misc

MAINTAINER=	fuz@fuz.su
COMMENT=	Collection of tools and libraries by J. Schilling (metaport)
WWW=		https://codeberg.org/schilytools/schilytools

RUN_DEPENDS=	bosh>=2022.08.18.b:shells/bosh \
		schilybase>=2021.05.19:devel/schilybase \
		schilyutils>=2021.05.19:sysutils/schilyutils \
		star>=2021.05.19:archivers/star \
		sccs>=2021.05.19:devel/sccs \
		smake>=2021.05.19:devel/smake \
		sunpromake>=2021.05.19:devel/sunpromake \
		ved>=2021.05.19:editors/ved \
		cdrtools>=2021.05.19:sysutils/cdrtools \
		rscsi>=2021.05.19:net/rscsi

USES=		metaport

OPTIONS_DEFINE=	DEPRECATED
DEPRECATED_DESC=	include deprecated utilities
DEPRECATED_RUN_DEPENDS=	man2html:textproc/man2html

.include <bsd.port.mk>
