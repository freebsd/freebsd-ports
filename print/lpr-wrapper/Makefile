# Created by: e-masson@kisoft-services.com
# $FreeBSD$

PORTNAME=	lpr-wrapper
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://www.mathstat.dal.ca/~selinger/lpr-wrapper/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User level printer frontend

RUN_DEPENDS=	bash:shells/bash \
		ppdfilt:print/libppd \
		psdim:print/psdim \
		mpage:print/mpage \
		pstops:print/psutils

USES=		ghostscript:run shebangfix
SHEBANG_FILES=	lpr-wrapper.in lpr-wrapper-cups.in lpr-wrapper-features
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/lpr-wrapper bin/lpr-wrapper-cups bin/lpr-wrapper-features

.include <bsd.port.mk>
