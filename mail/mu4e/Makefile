# $FreeBSD$

PORTNAME=	mu4e
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	mail
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Emacs frontend for Mu

LICENSE=	GPLv3

.if ${FLAVOR:U} != devel && ${FLAVOR:U} != devel_nox
# http://pkg.awarnach.mathstat.dal.ca/data/11i386-default/2018-05-30_07h36m11s/logs/errors/mu4e-emacs26-1.0_1.log
BROKEN=		fails to build
.endif

RUN_DEPENDS=	mu:mail/mu

USES=		autoreconf emacs gmake makeinfo pkgconfig
USE_GITHUB=	yes
GH_PROJECT=	mu
GH_ACCOUNT=	djcb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk \
		--disable-webkit \
		--disable-guile \
		--docdir="${DOCSDIR}" \
		--enable-mu4e
INFO=		mu4e
BUILD_WRKSRC=	${WRKSRC}/mu4e
INSTALL_WRKSRC=	${WRKSRC}/mu4e
INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

post-install:
	cd ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/mu4e && \
	    ${GZIP_CMD} *.el

.include <bsd.port.mk>
