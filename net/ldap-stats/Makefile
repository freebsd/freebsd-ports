# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	ldap-stats
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to generate OpenLDAP statistics reports

NO_ARCH=	yes
NO_BUILD=	yes
USES=		perl5

PLIST_FILES=	bin/ldap-stats

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ldap-stats.pl \
		${STAGEDIR}${PREFIX}/bin/ldap-stats

.include <bsd.port.mk>
