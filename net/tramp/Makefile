# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>

PORTNAME=	tramp
PORTVERSION=	2.3.0
PORTREVISION=	12
CATEGORIES=	net elisp
MASTER_SITES=	GNU
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent remote file access tool for Emacs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe emacs gmake makeinfo

GNU_CONFIGURE=	yes
CPE_VENDOR=	gnu

TRAMP_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
PLIST_SUB+=	TRAMP_LISPDIR=${TRAMP_LISPDIR}
CONFIGURE_ENV=	TEXI2DVI=no
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${TRAMP_LISPDIR} \
		--with-emacs=${EMACS_CMD}

INFO=		tramp

post-patch:
	@${REINPLACE_CMD} 's/^make/${MAKE_CMD}/' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${FLAVOR:U} != nox && ${FLAVOR:U} != devel_nox
.if ! ( ${OSVERSION} >= 1300000 && ${FLAVOR:U} == devel_full )
PLIST_FILES+=	${TRAMP_LISPDIR}/tramp-gvfs.el ${TRAMP_LISPDIR}/tramp-gvfs.elc
.endif
.endif

.include <bsd.port.post.mk>
