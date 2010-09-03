# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nmap
DISTVERSION=	5.35DC1
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/ \
		http://nmap.ucsd.edu/dist/ \
		http://www.mirrors.wiretapped.net/security/network-mapping/nmap/ \
		http://www.mirrorservice.org/sites/ftp.wiretapped.net/pub/security/network-mapping/nmap/ \
		http://mirror.sg.depaul.edu/pub/security/nmap/

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Port scanning utility for large networks

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

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
PLIST_SUB+=	NCATDATADIR=share/ncat \
		NPINGDIR=share/nping

.ifndef WITHOUT_SSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${OPENSSLINC}"
PLIST_SUB+=		WITHSSL=""
.else
CONFIGURE_ARGS+=	--without-openssl
PLIST_SUB+=		WITHSSL="@comment "
.endif

# XXX limit results if we do a grep in the sources!
post-patch:
	@${RM} -rf ${WRKSRC}/mswin32

post-configure:
	@${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|" ${WRKSRC}/Makefile

post-install:
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@for doc in CHANGELOG HACKING docs/nmap.dtd; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
