# $FreeBSD$

PORTNAME=	mu4e
PORTVERSION=	1.2
CATEGORIES=	mail
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Emacs frontend for Mu

LICENSE=	GPLv3

RUN_DEPENDS=	mu:mail/mu

USES=		autoreconf emacs makeinfo pkgconfig
USE_GITHUB=	yes
GH_PROJECT=	mu
GH_ACCOUNT=	djcb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk \
		--disable-webkit \
		--disable-guile \
		--docdir="${DOCSDIR}" \
		--enable-mu4e
INFO=		${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

pre-build:
	${REINPLACE_CMD} -e '/.el.elc/,/^$$/d' ${BUILD_WRKSRC}/Makefile && \
	    ${ECHO_CMD} '.include "${FILESDIR}/byte-compile.mk"' \
	    >> ${BUILD_WRKSRC}/Makefile

post-install:
	cd ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/mu4e && \
	    ${GZIP_CMD} *.el

.include <bsd.port.mk>
