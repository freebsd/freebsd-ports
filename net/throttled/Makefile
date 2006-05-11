# Ports collection makefile for:	throttled
# Date created:			11 Jun 2004
# Whom:				quest <quest@mac.com>
#
# $FreeBSD$
#

PORTNAME=	throttled
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	http://www.intrarts.com/Files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	quest@mac.com
COMMENT=	Bandwidth shaping and QoS solution

USE_GMAKE=	yes

PLIST_FILES=	sbin/throttled sbin/throttled-startup

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" \
	${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|c++|${CXX}|;s|-O3|${CXXFLAGS}| \
	;s|-pthread|${PTHREAD_LIBS}|" ${WRKSRC}/src/Makefile

.include <bsd.port.mk>
