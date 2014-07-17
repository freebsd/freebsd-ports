# Created by: e-masson@kisoft-services.com
# $FreeBSD$

PORTNAME=	lpr-wrapper
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.mathstat.dal.ca/~selinger/lpr-wrapper/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User level printer frontend

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		ppdfilt:${PORTSDIR}/print/libppd \
		psdim:${PORTSDIR}/print/psdim \
		mpage:${PORTSDIR}/print/mpage \
		pstops:${PORTSDIR}/print/psutils

USES=		shebangfix
SHEBANG_FILES=	lpr-wrapper.in lpr-wrapper-cups.in lpr-wrapper-features
USE_GHOSTSCRIPT_RUN=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/lpr-wrapper bin/lpr-wrapper-cups bin/lpr-wrapper-features

.include <bsd.port.mk>
