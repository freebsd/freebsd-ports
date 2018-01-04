# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tramp
PORTVERSION=	2.3.0
PORTREVISION=	3
CATEGORIES=	net elisp
MASTER_SITES=	GNU
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Transparent remote file access tool for emacsen

USE_EMACS=	yes

GNU_CONFIGURE=	yes
USES=		cpe gmake makeinfo
CPE_VENDOR=	gnu

TRAMP_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
PLIST_SUB+=	TRAMP_LISPDIR=${TRAMP_LISPDIR}
CONFIGURE_ENV=	TEXI2DVI=no
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${TRAMP_LISPDIR} \
		--with-emacs=${EMACS_CMD}

INFO=		tramp

post-patch:
	@${REINPLACE_CMD} 's/^make/${MAKE_CMD}/' ${WRKSRC}/configure

.include <bsd.port.mk>
