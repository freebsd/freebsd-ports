# Created by: rdenis@simphalempin.com
# $FreeBSD$

PORTNAME=	ndisc6
PORTVERSION=	1.0.2
PORTREVISION=	2
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LDFLAGS+=	-lintl
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

USE_RC_SUBR=	rdnssd

PORTDOCS=	AUTHORS NEWS README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
