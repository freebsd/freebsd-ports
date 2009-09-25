# New ports collection makefile for:	sipcalc
# Date created:				24.03.2002
# Whom:					Janos.Mohacsi@dante.org.uk
#
# $FreeBSD$
#

PORTNAME=	sipcalc
PORTVERSION=	1.1.5
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.routemeister.net/projects/sipcalc/files/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Sipcalc is an IP subnet calculator with IPv6 support

GNU_CONFIGURE=	yes
MAN1=		sipcalc.1

DOC_FILES=	doc/sipcalc.txt ChangeLog README

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
