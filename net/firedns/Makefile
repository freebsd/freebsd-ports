# New ports collection makefile for:	firedns
# Date created:		Sun 12 May 22:30:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	firedns
PORTVERSION=	0.1.30
CATEGORIES=	net devel
MASTER_SITES=	http://ares.penguinhosting.net/~ian/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	-${PORTVERSION}.tar.gz

MAINTAINER=	dean@odyssey.apana.org.au

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:${PORTSDIR}/misc/firestring

HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

MAN3=		firedns_aton4.3 firedns_aton6.3 firedns_dnsbl_lookup.3 \
		firedns_getip4.3 firedns_getip6.3 firedns_getmx.3 \
		firedns_getname4.3 firedns_getname6.3 \
		firedns_getresult.3 firedns_gettxt.3 firedns_ntoa4.3 \
		firedns_ntoa6.3 firedns_resolveip4.3 \
		firedns_resolveip6.3  firedns_resolvemx.3 \
		firedns_resolvename4.3 firedns_resolvename6.3 \
		firedns_resolvetxt.3 libfiredns.3

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/firemake.cflags ${WRKSRC}/firemake.ldflags

post-install:
	@cd ${PREFIX}/lib; ${MV} libfiredns.so libfiredns.so.0; \
	${LN} -s libfiredns.so.0 libfiredns.so

.include <bsd.port.mk>
