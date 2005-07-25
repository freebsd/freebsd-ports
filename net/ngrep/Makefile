# ex:ts=8
# Ports collection makefile for:  ngrep
# Date created:			  Sat Jan 01, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ngrep
PORTVERSION=	1.43
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Network grep

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre \
		--disable-pcap-restart \
		--enable-dropprivs-onlyroot \
		--mandir=${PREFIX}/man/
ALL_TARGET=	ngrep
USE_BZIP2=	yes

MAN8=		ngrep.8
PLIST_FILES=	bin/ngrep

PORTDOCS=	CHANGES.txt CREDITS.txt INSTALL.txt LICENSE.txt \
		README.txt REGEX.txt

.include <bsd.port.pre.mk>

.if !defined(WITH_PORTS_PCAP)
CONFIGURE_ARGS+=--with-pcap-includes=/usr/include
.else
CONFIGURE_ARGS+=--with-pcap-includes=${LOCALBASE}/include
LIB_DEPENDS=   pcap.2:${PORTSDIR}/net/libpcap
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
