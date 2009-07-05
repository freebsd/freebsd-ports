# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nmap
DISTVERSION=	4.90RC1
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/ \
		http://www.mirrors.wiretapped.net/security/network-mapping/nmap/ \
		http://www.mirrorservice.org/sites/ftp.wiretapped.net/pub/security/network-mapping/nmap/ \
		http://mirror.sg.depaul.edu/pub/security/nmap/

MAINTAINER=	daniel@roe.ch
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

MAN1=		nmap.1 ncat.1
PLIST_SUB=	NCATDATADIR=share/ncat

.ifndef WITHOUT_SSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${OPENSSLINC}"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

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
