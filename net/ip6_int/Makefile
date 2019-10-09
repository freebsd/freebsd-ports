# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	ip6_int
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.bieringer.de/linux/IPv6/tools/
DISTNAME=	ip6_int
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert an IPv4/IPv6 address to an in-addr.arpa/ip6.int PTR value

PLIST_FILES=	bin/ip6_int
NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	ip6_int

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ip6_int ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
