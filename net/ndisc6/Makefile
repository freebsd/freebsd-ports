# Created by: rdenis@simphalempin.com
# $FreeBSD$

PORTNAME=	ndisc6
PORTVERSION=	1.0.3
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.remlab.net/files/ndisc6/ \
		http://people.via.ecp.fr/~rem/www.remlab.net/files/ndisc6/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	IPv6 network diagnostic tools

LICENSE=	GPLv2

USES=		tar:bzip2 perl5
USE_GCC=	any

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suid-install --localstatedir="${PREFIX}/var"
CONFIGURE_ENV=	PERL=${LOCALBASE}/bin/perl
MAKE_ENV=	CHOWNPROG=:

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_LDFLAGS=	-lintl

USE_RC_SUBR=	rdnssd

PORTDOCS=	AUTHORS NEWS README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
