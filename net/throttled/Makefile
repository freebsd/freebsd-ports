PORTNAME=	throttled
PORTVERSION=	0.5.2
CATEGORIES=	net
MASTER_SITES=	http://www.intrarts.com/Files/

MAINTAINER=	quest@mac.com
COMMENT=	Bandwidth shaping and QoS solution

LICENSE=	GPLv3

USES=		gmake tar:tgz
USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	sbin/throttled sbin/throttled-startup

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${STAGEDIR}${PREFIX}|g" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|c++|${CXX}|;s|-O3|${CXXFLAGS}|" \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
