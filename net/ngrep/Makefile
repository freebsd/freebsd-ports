# ex:ts=8
# Ports collection makefile for:  ngrep
# Date created:			  Sat Jan 01, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ngrep
PORTVERSION=	1.44
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	edwin@mavetju.org
COMMENT=	Network grep

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
ALL_TARGET=	ngrep
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man/ --disable-pcap-restart

OPTIONS=	PCRE	"Use PCRE instead of GNU regex"	on \
		PORTS_PCAP	"Use ports PCAP instead of system PCAP" off \
		IPV6	"Enable IPv6 support" on

MAN8=		ngrep.8
PLIST_FILES=	bin/ngrep

PORTDOCS=	CHANGES.txt CREDITS.txt INSTALL.txt LICENSE.txt \
		README.txt REGEX.txt

.include <bsd.port.pre.mk>

.if defined(WITH_PCRE)
CONFIGURE_ARGS+=	--enable-pcre
.endif

.if !defined(WITH_PORTS_PCAP)
CONFIGURE_ARGS+=	--with-pcap-includes=/usr/include
.else
CONFIGURE_ARGS+=	--with-pcap-includes=${LOCALBASE}/include
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
.if defined(WITH_PORTS_PCAP)
	@${REINPLACE_CMD} -e "s|-lpcap|${LOCALBASE}/lib/libpcap.a|g" \
		${WRKSRC}/Makefile.in ${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@if [ -f ${WRKSRC}/${file} ]; then \
		${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}; \
	else \
		${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}; \
	fi
.endfor
.endif

.include <bsd.port.post.mk>
