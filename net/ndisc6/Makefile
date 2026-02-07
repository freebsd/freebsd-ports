PORTNAME=	ndisc6
DISTVERSION=	1.0.8
CATEGORIES=	net
MASTER_SITES=	http://www.remlab.net/files/ndisc6/

MAINTAINER=	takefu@airport.fm
COMMENT=	IPv6 network diagnostic tools
WWW=		https://www.remlab.net/ndisc6/

LICENSE=	GPLv2

USES=		compiler:c11 localbase perl5 tar:bzip2
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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:M*:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
