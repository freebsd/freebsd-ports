# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nmap
PORTVERSION=	5.50
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/ \
		LOCAL/ohauer

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Port scanning utility for large networks

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

# http://nmap.org/book/man-legal.html
LICENSE=	GPLv2

USE_LUA=	5.1
LUA_COMPS=	lua
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-localdirs \
		--without-zenmap \
		--without-ndiff \
		--with-libpcre=${LOCALBASE} \
		--with-liblua=${LOCALBASE}
CONFIGURE_ENV=	LUA_INCDIR="${LUA_INCDIR}" LUA_LIBDIR="${LUA_LIBDIR}"

MANLANG=	"" de es fr hr hu it jp pl pt_BR pt_PT ro ru sk zh
MAN1=		nmap.1
MAN1_EN=	ncat.1 nping.1

.ifndef WITHOUT_SSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${OPENSSLINC}"
PLIST_SUB+=		WITHSSL=""
.else
PKGNAMESUFFIX=		-nossl
CONFIGURE_ARGS+=	--without-openssl
PLIST_SUB+=		WITHSSL="@comment "
.endif

PORTDOCS=	CHANGELOG HACKING
EXAMPLES=	docs/sample-script.nse
PORTEXAMPLES=	${EXAMPLES:T}

# XXX limit results if we do a grep in the sources!
post-extract:
	@${RM} -rf ${WRKSRC}/mswin32

post-configure:
	@${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|" ${WRKSRC}/Makefile

post-install:
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
.endif
.ifndef NOPORTEXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
.	for i in ${EXAMPLES}
		@${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}
.	endfor
.endif

.include <bsd.port.mk>
