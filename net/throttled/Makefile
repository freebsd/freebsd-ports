# Ports collection makefile for:	throttled
# Date created:			11 Jun 2004
# Whom:				quest <quest@mac.com>
#
# $FreeBSD$
#

PORTNAME=	throttled
PORTVERSION=	0.3.2
CATEGORIES=	net
MASTER_SITES=	http://www.intrarts.com/Files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	quest@mac.com
COMMENT=	Bandwidth shaping and QoS solution

USE_REINPLACE=	yes
USE_GMAKE=	yes

PLIST_FILES=	sbin/throttled sbin/throttled-startup

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 499999
IGNORE=		"is for FreeBSD 4.X only"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|install: all|install: $$\{APPNAME\}|" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" \
		${WRKSRC}/Makefile \
		${WRKSRC}/throttled-startup
	@${REINPLACE_CMD} -e "s|c++|${CXX}|;s|-O3|${CXXFLAGS}|" \
		${WRKSRC}/src/Makefile

.include <bsd.port.post.mk>
