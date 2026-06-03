PORTNAME=	ndisc6
DISTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.remlab.net/files/ndisc6/ \
		LOCAL/je3kmz:gmo
DISTFILES=	${DISTNAME}.tar.bz2 \
		${DISTNAME}_ja.tar.xz:gmo

MAINTAINER=	takefu@airport.fm
COMMENT=	IPv6 network diagnostic tools
WWW=		https://www.remlab.net/ndisc6/

LICENSE=	GPLv2

USES=		compiler:c11 localbase perl5 tar:bzip2 tar:xz
USE_RC_SUBR=	rdnssd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suid-install \
		--localstatedir="${PREFIX}/var"
CONFIGURE_ENV=	PERL=${LOCALBASE}/bin/perl
MAKE_ENV=	CHOWNPROG=:
PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
NLS_LDFLAGS=		-lintl

pre-patch-NLS-on:
	${CP} ${WRKDIR}/${DISTNAME}_ja.gmo ${WRKSRC}/po/ja.gmo
	${CP} ${WRKDIR}/${DISTNAME}_ja.po ${WRKSRC}/po/ja.po

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:M*:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
