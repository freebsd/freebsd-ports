# Created by: Janos.Mohacsi@dante.org.uk
# $FreeBSD$

PORTNAME=	sipcalc
PORTVERSION=	1.1.5
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.routemeister.net/projects/sipcalc/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sipcalc is an IP subnet calculator with IPv6 support

GNU_CONFIGURE=	yes

DOC_FILES=	doc/sipcalc.txt ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
