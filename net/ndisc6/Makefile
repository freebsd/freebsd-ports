PORTNAME=	ndisc6
PORTVERSION=	1.0.5
CATEGORIES=	net
MASTER_SITES=	http://www.remlab.net/files/ndisc6/ \
		http://people.via.ecp.fr/~rem/www.remlab.net/files/ndisc6/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPv6 network diagnostic tools

LICENSE=	GPLv2

USES=		compiler:c11 perl5 tar:bzip2
USE_RC_SUBR=	rdnssd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suid-install \
		--localstatedir="${PREFIX}/var"
CONFIGURE_ENV=	PERL=${LOCALBASE}/bin/perl
MAKE_ENV=	CHOWNPROG=:

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_LDFLAGS=		-lintl

PORTDOCS=	AUTHORS NEWS README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
